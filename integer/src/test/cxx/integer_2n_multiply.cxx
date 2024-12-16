// Copyright (C) 2024 Pedro Lamarão <pedro.lamarao@gmail.com>. All rights reserved.

#include <gtest/gtest.h>

import br.dev.pedrolamarao.crypto.integer;
import br.dev.pedrolamarao.crypto.integer.test;

using namespace br::dev::pedrolamarao::crypto::integer;
using namespace std;

TYPED_TEST(integer_2n_test,product_1_0_0)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_0_1)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_0_2)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = 2;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_0_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_1_0)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_1_1)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 1u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_1_2)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 2;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 2u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_1_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], max );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_2_0)
{
    auto x = TypeParam::create(1);
    x[0] = 2;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_2_1)
{
    auto x = TypeParam::create(1);
    x[0] = 2;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 2u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_2_2)
{
    auto x = TypeParam::create(1);
    x[0] = 2;

    auto y = TypeParam::create(1);
    y[0] = 2;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 4u );
    ASSERT_EQ( z[1], 0u );
}

TYPED_TEST(integer_2n_test,product_1_2_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++
    unit max_predecessor = unit(-2); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 2;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], max_predecessor );
    ASSERT_EQ( z[1], 1 );
}

TYPED_TEST(integer_2n_test,product_1_max_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 0 );
    ASSERT_EQ( z[1], 0 );
}

TYPED_TEST(integer_2n_test,product_1_max_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], max );
    ASSERT_EQ( z[1], 0 );
}

TYPED_TEST(integer_2n_test,product_1_max_2)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++
    unit max_predecessor = unit(-2); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = 2;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], max_predecessor );
    ASSERT_EQ( z[1], 1 );
}

TYPED_TEST(integer_2n_test,product_1_max_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++
    unit max_predecessor = unit(-2); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 2 );
    ASSERT_EQ( z[0], 1 );
    ASSERT_EQ( z[1], max_predecessor );
}

// --

TYPED_TEST(integer_2n_test,product_2_0_0)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_0_1)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_0_2)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 2;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_0_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_1_0)
{
    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_1_1)
{
    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 1u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_1_2)
{
    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 2;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 2u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_1_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], max );
    ASSERT_EQ( z[1], max );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_2_0)
{
    auto x = TypeParam::create(2);
    x[0] = 2;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_2_1)
{
    auto x = TypeParam::create(2);
    x[0] = 2;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 2u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_2_2)
{
    auto x = TypeParam::create(2);
    x[0] = 2;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 2;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 4u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_2_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++
    unit max_predecessor = unit(-2); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 2;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], max_predecessor );
    ASSERT_EQ( z[1], max );
    ASSERT_EQ( z[2], 1 );
    ASSERT_EQ( z[3], 0 );
}

TYPED_TEST(integer_2n_test,product_2_max_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 0u );
    ASSERT_EQ( z[1], 0u );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_max_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], max );
    ASSERT_EQ( z[1], max );
    ASSERT_EQ( z[2], 0u );
    ASSERT_EQ( z[3], 0u );
}

TYPED_TEST(integer_2n_test,product_2_max_2)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++
    unit max_predecessor = unit(-2); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = 2;
    y[1] = 0;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], max_predecessor );
    ASSERT_EQ( z[1], max );
    ASSERT_EQ( z[2], 1 );
    ASSERT_EQ( z[3], 0 );
}

TYPED_TEST(integer_2n_test,product_2_max_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++
    unit max_predecessor = unit(-2); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto z = multiply(x,y);

    ASSERT_EQ( z.digits(), 4 );
    ASSERT_EQ( z[0], 1 );
    ASSERT_EQ( z[1], 0 );
    ASSERT_EQ( z[2], max_predecessor );
    ASSERT_EQ( z[3], max );
}