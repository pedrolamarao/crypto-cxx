#include <numeric>

#include <gmock/gmock.h>

import br.dev.pedrolamarao.crypto.integer;

using namespace br::dev::pedrolamarao::crypto::integer;
using namespace std;

TEST(integer,sum_accumulate_equisized_1_0_0)
{
    auto x = integer::create(1);
    auto y = integer::create(1);

    x[0] = 0;
    y[0] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( carry, 0 );
}

TEST(integer,sum_accumulate_equisized_1_0_1)
{
    auto x = integer::create(1);
    auto y = integer::create(1);

    x[0] = 0;
    y[0] = 1;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0], 1 );
}

TEST(integer,sum_accumulate_equisized_1_max_1)
{
    auto x = integer::create(1);
    auto y = integer::create(1);

    x[0] = numeric_limits<digit>::max();
    y[0] = 1;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0], 0 );
    ASSERT_EQ( carry, 1 );
}

TEST(integer,sum_accumulate_equisized_2_max_1)
{
    auto x = integer::create(2);
    auto y = integer::create(2);

    x[0] = numeric_limits<digit>::max();
    x[1] = numeric_limits<digit>::max();
    y[0] = 1;
    y[1] = 0;

    auto carry = sum_accumulate_equisized(x,y);

    ASSERT_EQ( x[0], 0 );
    ASSERT_EQ( x[1], 0 );
    ASSERT_EQ( carry, 1 );
}

TEST(integer,sum_equisized_1_0_1)
{
    auto x = integer::create(1);
    auto y = integer::create(1);

    x[0] = 0;
    y[0] = 1;

    auto [z,carry] = sum_equisized(x,y);

    ASSERT_EQ( z[0], 1 );
}

TEST(integer,sum_equisized_1_max_1)
{
    auto x = integer::create(1);
    auto y = integer::create(1);

    x[0] = numeric_limits<digit>::max();
    y[0] = 1;

    auto [z,carry] = sum_equisized(x,y);

    ASSERT_EQ( z[0], 0 );
    ASSERT_EQ( carry, 1 );
}

TEST(integer,sum_equisized_2_max_1)
{
    auto x = integer::create(2);
    auto y = integer::create(2);

    x[0] = numeric_limits<digit>::max();
    x[1] = numeric_limits<digit>::max();
    y[0] = 1;
    y[1] = 0;

    auto [z,carry] = sum_equisized(x,y);

    ASSERT_EQ( z[0], 0 );
    ASSERT_EQ( z[1], 0 );
    ASSERT_EQ( carry, 1 );
}
