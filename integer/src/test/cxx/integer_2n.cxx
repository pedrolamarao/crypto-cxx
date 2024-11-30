#include <numeric>

#include <gmock/gmock.h>

import br.dev.pedrolamarao.crypto.integer;

using namespace br::dev::pedrolamarao::crypto::integer;
using namespace std;

template <typename T>
struct integer_2n_test : testing::Test
{ };

using integer_2n_types = testing::Types<integer_2n<8>,integer_2n<16>,integer_2n<32>,integer_2n<64>>;

TYPED_TEST_SUITE(integer_2n_test,integer_2n_types);

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_1_0_0)
{
    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 0;
    y[0] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_1_0_1)
{
    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 0;
    y[0] = 1;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_1_0_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 0;
    y[0] = max;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_1_1_0)
{
    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 1;
    y[0] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_1_1_1)
{
    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 1;
    y[0] = 1;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  2 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_1_1_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 1;
    y[0] = max;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_1_max_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = max;
    y[0] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_1_max_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = max;
    y[0] = 1;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0], 0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_1_max_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = max;
    y[0] = max;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max - 1 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_2_0_0)
{
    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 0;
    x[1] = 0;
    y[0] = 0;
    y[1] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_2_0_1)
{
    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 0;
    x[1] = 0;
    y[0] = 1;
    y[1] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_2_0_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 0;
    x[1] = 0;
    y[0] = max;
    y[1] = max;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( x[1],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_2_1_0)
{
    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 1;
    x[1] = 0;
    y[0] = 0;
    y[1] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_2_1_1)
{
    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 1;
    x[1] = 0;
    y[0] = 1;
    y[1] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  2 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_2_1_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 1;
    x[1] = 0;
    y[0] = max;
    y[1] = max;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_2_max_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = max;
    x[1] = max;
    y[0] = 0;
    y[1] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( x[1],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_2_max_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = max;
    x[1] = max;
    y[0] = 1;
    y[1] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,sum_accumulate_equisized_2_max_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = max;
    x[1] = max;
    y[0] = max;
    y[1] = max;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max - 1 );
    ASSERT_EQ( x[1],  max );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_1_0_0)
{
    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 0;
    y[0] = 0;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_1_0_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 0;
    y[0] = 1;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_1_0_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 0;
    y[0] = max;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_1_1_0)
{
    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 1;
    y[0] = 0;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_1_1_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 1;
    y[0] = 1;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_1_1_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    auto y = TypeParam::create(1);

    x[0] = 1;
    y[0] = max;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  2 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_0_0)
{
    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 0;
    x[1] = 0;
    y[0] = 0;
    y[1] = 0;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_0_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 0;
    x[1] = 0;
    y[0] = 1;
    y[1] = 0;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( x[1],  max );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_0_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 0;
    x[1] = 0;
    y[0] = max;
    y[1] = max;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_1_0)
{
    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 1;
    x[1] = 0;
    y[0] = 0;
    y[1] = 0;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_1_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 1;
    x[1] = 0;
    y[0] = 1;
    y[1] = 0;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_1_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = 1;
    x[1] = 0;
    y[0] = max;
    y[1] = max;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  2 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_max_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = max;
    x[1] = max;
    y[0] = 0;
    y[1] = 0;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( x[1],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_max_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = max;
    x[1] = max;
    y[0] = 1;
    y[1] = 0;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  max - 1 );
    ASSERT_EQ( x[1],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_max_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    auto y = TypeParam::create(2);

    x[0] = max;
    x[1] = max;
    y[0] = max;
    y[1] = max;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}
