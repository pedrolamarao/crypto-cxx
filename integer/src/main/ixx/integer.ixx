module;

#include <algorithm>
#include <cstdint>
#include <tuple>

export module br.dev.pedrolamarao.crypto.integer;

using namespace std;

namespace br::dev::pedrolamarao::crypto::integer
{
    using bit = unsigned _BitInt(1);

    // crypto integer.
    // base 2^N.
    // big endian.
    // arithmetic modulo 2^N.
    // requires: N > 0
    export
    template <unsigned N>
    class integer_2n
    {
    public:

        // crypto integer storage unit.
        // native arithmetic is modulo 2^N.
        using unit = unsigned _BitInt(N);

        // returns: 1 if is lesser, 0 otherwise
        constexpr auto is_lesser (unit x, unit y) noexcept -> bit
        {
            unit z { x - y };
            return (z ^ ((y ^ x) & (y ^ z))) >> (N - 1);
        }

    private:

        // crypto integer storage.
        // stores length followed by digits.
        unit * ptr;

        // private constructor initializes ptr.
        explicit integer_2n (unit * ptr) noexcept : ptr{ptr} {}

    public:

        // construction and destruction

        // factory.
        // requires: digits > 0
        static
        auto create (size_t digits) -> integer_2n
        {
            auto units = digits + 1;
            auto ptr = new unit[units];
            fill_n(ptr,units,0);
            ptr[0] = digits;
            return integer_2n(ptr);
        }

        // move constructor.
        integer_2n (integer_2n && y) noexcept :
            ptr{y.ptr}
        {
            y.ptr = nullptr;
        }

        // move assignment.
        auto operator= (integer_2n && y) noexcept -> integer_2n &
        {
            using std::swap;
            swap(ptr,y.ptr);
            return *this;
        }

        // copy constructor.
        integer_2n (integer_2n const & y) :
            ptr{nullptr}
        {
            auto digits = y.digits();
            auto units = digits + 1;
            ptr = new unit[units];
            copy_n(y.ptr,units,ptr);
        }

        // copy assignment.
        auto operator= (integer_2n const & y) -> integer_2n &
        {
            using std::swap;
            auto tmp = y;
            swap(*this,tmp);
            return *this;
        }

        // destructor.
        ~integer_2n () noexcept
        {
            delete [] ptr;
        }

        // properties

        // digit accessor.
        // requires: i < digits()
        auto operator[] (size_t i) const -> unit const&
        {
            return ptr[i+1];
        }

        // digit accessor.
        // requires: i < digits()
        auto operator[] (size_t i) -> unit&
        {
            return ptr[i+1];
        }

        // digit count.
        auto digits () const -> size_t
        {
            return ptr[0];
        }

        // operators

        // requires: x.digits() == y.digits()
        // returns: carry
        auto sum_accumulate_equisized (integer_2n const& y) -> bit
        {
            bit carry {};
            for (size_t i = 0, j = digits(); i < j; ++i)
            {
                // load
                unit xdigit = (*this)[i];
                unit ydigit = y[i];
                // sum 1
                unit sum0 = xdigit + ydigit;
                bit carry0 = is_lesser(sum0,xdigit);
                // sum 2
                unit sum1 = sum0 + carry;
                bit carry1 = is_lesser(sum1,sum0);
                // store
                carry = carry1 | carry0;
                (*this)[i] = sum1;
            }
            return carry;
        }

        // requires: x.digits() == y.digits()
        // returns: carry
        auto difference_accumulate_equisized (integer_2n const& y) -> bit
        {
            bit carry {};
            for (size_t i = 0, j = digits(); i < j; ++i)
            {
                // load
                unit xdigit = (*this)[i];
                unit ydigit = y[i];
                // difference 1
                unit difference0 = xdigit - ydigit;
                bit carry0 = is_lesser(xdigit,difference0);
                // difference 2
                unit difference1 = difference0 - carry;
                bit carry1 = is_lesser(difference0,difference1);
                // store
                carry = carry1 | carry0;
                (*this)[i] = difference1;
            }
            return carry;
        }
    };

    // requires: x.digits() == y.digits()
    export
    template <unsigned N>
    auto sum_accumulate_equisized (integer_2n<N>& x, integer_2n<N> const& y) -> bit
    {
        return x.sum_accumulate_equisized(y);
    }

    // requires: x.digits() == y.digits()
    export
    template <unsigned N>
    auto sum_equisized (integer_2n<N> const& x, integer_2n<N> const& y) -> tuple< integer_2n<N>, bit >
    {
        auto sum = x;
        auto carry = sum.sum_accumulate_equisized(y);
        return { std::move(sum), carry };
    }

    // requires: x.digits() == y.digits()
    export
    template <unsigned N>
    auto difference_accumulate_equisized (integer_2n<N>& x, integer_2n<N> const& y) -> bit
    {
        return x.difference_accumulate_equisized(y);
    }

    // requires: x.digits() == y.digits()
    export
    template <unsigned N>
    auto difference_equisized (integer_2n<N> const& x, integer_2n<N> const& y) -> tuple< integer_2n<N>, bit >
    {
        auto difference = x;
        auto carry = difference.difference_accumulate_equisized(y);
        return { std::move(difference), carry };
    }

    export
    template <unsigned N>
    auto product (integer_2n<N> const& x, integer_2n<N> const& y) -> integer_2n<N>
    {
        using unit = unsigned _BitInt(N);
        using large = unsigned _BitInt(N*2);
        auto z = integer_2n<N>::create( x.digits() + y.digits() );
        auto const xz = x.digits();
        auto const yz = y.digits();
        for (size_t j = 0; j < yz; ++j) {
            unit carry {};
            for (size_t i = 0; i < xz; ++i) {
                large xd { x[i] };
                large yd { y[j] };
                large zd { z[i+j] };
                large p { ( xd * yd ) + zd + carry };
                carry = p >> N;
                z[i+j] = p;
            }
            z[j+xz] = carry;
        }
        return std::move(z);
    }
}
