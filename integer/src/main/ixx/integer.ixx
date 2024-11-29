module;

#include <cstdint>
#include <cstring>
#include <tuple>

export module br.dev.pedrolamarao.crypto.integer;

using namespace std;

namespace br::dev::pedrolamarao::crypto::integer
{
    export using digit = uint8_t;

    constexpr auto is_lesser (digit x, digit y) noexcept -> digit
    {
        digit z = x - y;
        return (z ^ ((y ^ x) & (y ^ z))) >> 7;
    }

    export class integer
    {
        digit * ptr;

        explicit integer (digit * ptr) noexcept :
            ptr(ptr)
        { }

    public:

        // life cycle

        integer (integer&& other) noexcept :
            ptr(other.ptr)
        {
            other.ptr = nullptr;
        }

        integer (integer const&) = delete;

        ~integer ()
        {
            delete[] ptr;
        }

        auto operator= (integer&& other) noexcept -> integer&
        {
            using std::swap;
            swap(ptr,other.ptr);
            return *this;
        }

        auto operator= (integer const&) -> integer& = delete;

        static auto copy (integer const& i)
        {
            auto size = i.size() + 1;
            auto ptr = new digit[size];
            memcpy(ptr,i.ptr,size);
            return integer(ptr);
        }

        static auto create (digit n)
        {
            auto ptr = new digit[n+1];
            memset(ptr,0,n+1);
            ptr[0] = n;
            return integer(ptr);
        }

        // methods

        // requires: i < size()
        auto operator[] (size_t i) const -> digit const&
        {
            return ptr[i+1];
        }

        // requires: i < size()
        auto operator[] (size_t i) -> digit&
        {
            return ptr[i+1];
        }

        auto size () const -> digit
        {
            return ptr[0];
        }
    };

    // requires: x.size() == y.size()
    // returns: carry
    export auto sum_accumulate_equisized (integer& x, integer const& y) -> digit
    {
        digit carry {};
        for (size_t i = 0, j = x.size(); i < j; ++i)
        {
            digit xdigit = x[i];
            digit ydigit = y[i];
            digit sum0 = xdigit + ydigit;
            digit carry0 = is_lesser(sum0,xdigit);
            digit sum1 = sum0 + carry;
            digit carry1 = is_lesser(sum1,sum0);
            carry = carry1 | carry0;
            x[i] = sum1;
        }
        return carry;
    }

    // requires: x.size() == y.size()
    // returns carry
    export auto sum_equisized (integer const& x, integer const & y) -> tuple<integer,digit>
    {
        auto z = integer::copy(x);
        auto carry = sum_accumulate_equisized(z,y);
        return { std::move(z), carry };
    }
}
