// Copyright (C) 2024 Pedro Lamarão <pedro.lamarao@gmail.com>. All rights reserved.

module;

#include <algorithm>
#include <tuple>

export module br.dev.pedrolamarao.crypto.integer;

using namespace std;

namespace br::dev::pedrolamarao::crypto::integer
{
    // ( 1, 0 )
    using bit = unsigned _BitInt(1);

    export
    constexpr
    auto not_ (bit x)
    {
        return x ^ 1;
    }

    // integer.
    // base 2^B.
    // arithmetic modulo 2^B.
    template <unsigned B>
    requires requires { B > 1; }
    using word = unsigned _BitInt(B);

    export
    template <unsigned B>
    constexpr
    auto is_zero (word<B> x) -> bit
    {
        return ~(x | -x) >> (B - 1);
    }

    export
    template <unsigned B>
    constexpr
    auto not_zero (word<B> x) -> bit
    {
        return (x | -x) >> (B - 1);
    }

    export
    template <unsigned B>
    constexpr
    auto not_equal (word<B> x, word<B> y) -> bit
    {
        return not_zero( x ^ y );
    }

    export
    template <unsigned B>
    constexpr
    auto is_equal (word<B> x, word<B> y) -> bit
    {
        return is_zero( x ^ y );
    }

    export
    template <unsigned B>
    constexpr
    auto is_less (word<B> x, word<B> y) -> bit
    {
        auto z = x - y;
        return (z ^ ((y ^ x) & (y ^ z))) >> (B - 1);
    }

    export
    template <unsigned B>
    constexpr
    auto is_greater (word<B> x, word<B> y) -> bit
    {
        auto z = y - x;
        return (z ^ ((x ^ y) & (x ^ z))) >> (B - 1);
    }

    export
    template <unsigned B>
    constexpr
    auto select (bit control, word<B> x, word<B> y) -> word<B>
    {
        return y ^ (-control & (x ^ y));
    }

    // crypto integer.
    // base 2^B.
    // little endian.
    // arithmetic modulo 2^B.
    // requires: B > 1
    export
    template <unsigned B>
    class integer_2n
    {
    public:

        // crypto integer storage unit.
        // native arithmetic is modulo 2^B.
        using unit = word<B>;

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
    };

    // relations

    export
    template <unsigned B>
    auto is_zero (integer_2n<B> const & x) -> bit
    {
        using unit = typename integer_2n<B>::unit;
        auto const d = x.digits();
        unit z {};
        for (auto i = 0u; i != d; ++i) {
            z |= x[i];
        }
        return is_zero(z);
    }

    template <unsigned B>
    // requires: x.digits() >= y.digits()
    auto is_equal_0 (integer_2n<B> const & x, integer_2n<B> const & y) -> bit
    {
        using unit = typename integer_2n<B>::unit;
        auto const xd = x.digits();
        auto const yd = y.digits();
        unit z {};
        for (auto i = 0u; i != yd; ++i) {
            z |= x[i] ^ y[i];
        }
        for (auto i = yd; i != xd; ++i) {
            z |= x[i];
        }
        return is_zero(z);
    }

    export
    template <unsigned B>
    auto is_equal (integer_2n<B> const & x, integer_2n<B> const & y) -> bit
    {
        if (x.digits() >= y.digits()) return is_equal_0(x,y);
        else                          return is_equal_0(y,x);
    }

    // operators

    export
    template <unsigned B>
    // requires: x.digits() >= y.digits()
    auto add_accumulate (integer_2n<B> & x, integer_2n<B> const & y) -> bit
    {
        using unit = typename integer_2n<B>::unit;
        const auto xd = x.digits();
        const auto yd = y.digits();
        bit carry {};
        for (auto i = 0u; i < yd; ++i)
        {
            // load
            unit xi = x[i];
            unit yi = y[i];
            // sum 1
            unit sum0 = xi + yi;
            bit carry0 = is_less(sum0,xi);
            // sum 2
            unit sum1 = sum0 + carry;
            bit carry1 = is_less(sum1,sum0);
            // store
            carry = carry1 | carry0;
            x[i] = sum1;
        }
        for (auto i = yd; i != xd; ++i)
        {
            // load
            unit xi = x[i];
            // sum
            unit sum1 = xi + carry;
            bit carry1 = is_less(sum1,xi);
            // store
            carry = carry1;
            x[i] = sum1;
        }
        return carry;
    }

    template <unsigned B>
    // requires: x.digits() >= y.digits()
    auto add_0 (integer_2n<B> const & x, integer_2n<B> const & y) -> tuple< integer_2n<B>, bit >
    {
        auto z = x;
        auto carry = add_accumulate(z,y);
        return { std::move(z), carry };
    }

    export
    template <unsigned B>
    auto add (integer_2n<B> const & x, integer_2n<B> const & y) -> tuple< integer_2n<B>, bit >
    {
        if (x.digits() >= y.digits()) return add_0(x,y);
        else                          return add_0(y,x);
    }

    export
    template <unsigned B>
    // requires: x.digits() >= y.digits()
    auto subtract_accumulate (integer_2n<B>& x, integer_2n<B> const& y) -> bit
    {
        using unit = typename integer_2n<B>::unit;
        const auto xd = x.digits();
        const auto yd = y.digits();
        bit carry {};
        for (auto i = 0u; i < yd; ++i)
        {
            // load
            unit xi = x[i];
            unit yi = y[i];
            // difference 1
            unit difference0 = xi - yi;
            bit carry0 = is_less(xi,difference0);
            // difference 2
            unit difference1 = difference0 - carry;
            bit carry1 = is_less(difference0,difference1);
            // store
            carry = carry1 | carry0;
            x[i] = difference1;
        }
        for (auto i = yd; i != xd; ++i)
        {
            // load
            unit xi = x[i];
            // difference 2
            unit difference1 = xi - carry;
            bit carry1 = is_less(xi,difference1);
            // store
            carry = carry1;
            x[i] = difference1;
        }
        return carry;
    }

    export
    template <unsigned B>
    // requires: x.digits() >= y.digits()
    auto subtract (integer_2n<B> const & x, integer_2n<B> const & y) -> tuple< integer_2n<B>, bit >
    {
        auto z = x;
        auto carry = subtract_accumulate(z,y);
        return { std::move(z), carry };
    }

    export
    template <unsigned B>
    auto multiply (integer_2n<B> const& x, integer_2n<B> const& y) -> integer_2n<B>
    {
        using unit = word<B>;
        using large = word<B*2>;
        auto const xd = x.digits();
        auto const yd = y.digits();
        auto product = integer_2n<B>::create( xd + yd );
        for (size_t j = 0; j < yd; ++j) {
            unit carry {};
            for (size_t i = 0; i < xd; ++i) {
                // load
                large xi = x[i];
                large yi = y[j];
                large pij = product[i+j];
                // multiply and add
                large z = ( xi * yi ) + pij + carry;
                // store
                carry = z >> B;
                product[i+j] = z;
            }
            product[j+xd] = carry;
        }
        return std::move(product);
    }
}
