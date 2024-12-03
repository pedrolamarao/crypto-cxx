// Copyright (C) 2024 Pedro Lamarão <pedro.lamarao@gmail.com>. All rights reserved.

#include <gtest/gtest.h>

import br.dev.pedrolamarao.crypto.integer;
import br.dev.pedrolamarao.crypto.integer.test;

using namespace br::dev::pedrolamarao::crypto::integer;
using namespace std;

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_1_0_0)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
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
    x[0] = 0;

    auto y = TypeParam::create(1);
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
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_1_1_0)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
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
    x[0] = 1;

    auto y = TypeParam::create(1);
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
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  2 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_accumulate_equisized_2_0_0)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
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
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
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
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
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
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
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
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
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
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
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
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
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
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
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
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto carry = difference_accumulate_equisized(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_equisized_1_0_0)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_equisized_1_0_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], max );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_equisized_1_0_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 1 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_equisized_1_1_0)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_equisized_1_1_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_equisized_1_1_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 2 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_equisized_2_0_0)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 0 );
    ASSERT_EQ( difference[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_equisized_2_0_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], max );
    ASSERT_EQ( difference[1], max );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_equisized_2_0_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 1 );
    ASSERT_EQ( difference[1], 0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_equisized_2_1_0)
{
    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 1 );
    ASSERT_EQ( difference[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_equisized_2_1_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 0 );
    ASSERT_EQ( difference[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_equisized_2_1_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 2 );
    ASSERT_EQ( difference[1], 0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,difference_equisized_2_max_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], max );
    ASSERT_EQ( difference[1], max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_equisized_2_max_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], max - 1 );
    ASSERT_EQ( difference[1], max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,difference_equisized_2_max_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto [difference,carry] = difference_equisized(x,y);

    ASSERT_EQ( difference[0], 0 );
    ASSERT_EQ( difference[1], 0 );
    ASSERT_EQ( carry, 0 );
}
