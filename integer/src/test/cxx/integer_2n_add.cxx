// Copyright (C) 2024 Pedro Lamarão <pedro.lamarao@gmail.com>. All rights reserved.

#include <gtest/gtest.h>

import br.dev.pedrolamarao.crypto.integer;
import br.dev.pedrolamarao.crypto.integer.test;

using namespace br::dev::pedrolamarao::crypto::integer;
using namespace std;

TYPED_TEST(integer_2n_test,add_accumulate_0_0)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_0_1)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_0_M)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_1_0)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_1_1)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  2 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_1_M)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_accumulate_M_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_M_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0], 0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_accumulate_M_M)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  max - 1 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_accumulate_00_00)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_00_01)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_00_MM)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( x[1],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_01_00)
{
    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  1 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_01_01)
{
    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  2 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_01_MM)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_accumulate_MM_00)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  max );
    ASSERT_EQ( x[1],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_accumulate_MM_01)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  0 );
    ASSERT_EQ( x[1],  0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_accumulate_MM_MM)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto carry = add_accumulate(x,y);

    ASSERT_EQ( x[0],  max - 1 );
    ASSERT_EQ( x[1],  max );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_0_0)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0],  0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_0_1)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0],  1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_0_M)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_1_0)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0],  1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_1_1)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0],  2 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_1_M)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0],  0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_M_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0],  max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_M_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_M_M)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0],  max - 1 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_00_00)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry,  0 );
}

TYPED_TEST(integer_2n_test,add_00_10)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], 1 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry,  0 );
}

TYPED_TEST(integer_2n_test,add_00_MM)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], max );
    ASSERT_EQ( sum[1], max );
    ASSERT_EQ( carry,  0 );
}

TYPED_TEST(integer_2n_test,add_01_00)
{
    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], 1 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry,  0 );
}

TYPED_TEST(integer_2n_test,add_01_10)
{
    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], 2 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry,  0 );
}

TYPED_TEST(integer_2n_test,add_01_MM)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry,  1 );
}

TYPED_TEST(integer_2n_test,add_MM_00)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], max );
    ASSERT_EQ( sum[1], max );
    ASSERT_EQ( carry,  0 );
}

TYPED_TEST(integer_2n_test,add_MM_01)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry,  1 );
}

TYPED_TEST(integer_2n_test,add_MM_MM)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum[0], max - 1 );
    ASSERT_EQ( sum[1], max );
    ASSERT_EQ( carry,  1 );
}

TYPED_TEST(integer_2n_test,add_0_00)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_0_01)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 1 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_0_MM)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 0;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], max );
    ASSERT_EQ( sum[1], max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_1_00)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 1 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_1_01)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 2 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_1_MM)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_M_00)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(2);
    y[0] = 0;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], max );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_M_01)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(2);
    y[0] = 1;
    y[1] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( sum[1], 1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_M_MM)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto y = TypeParam::create(2);
    y[0] = max;
    y[1] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], max - 1 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_00_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_00_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 1 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_00_M)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], max );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_01_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 1 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_01_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 2 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_01_M)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( sum[1], 1 );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_MM_0)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(1);
    y[0] = 0;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], max );
    ASSERT_EQ( sum[1], max );
    ASSERT_EQ( carry, 0 );
}

TYPED_TEST(integer_2n_test,add_MM_1)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], 0 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 1 );
}

TYPED_TEST(integer_2n_test,add_MM_M)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto y = TypeParam::create(1);
    y[0] = max;

    auto [sum,carry] = add(x,y);

    ASSERT_EQ( sum.digits(), 2 );
    ASSERT_EQ( sum[0], max - 1 );
    ASSERT_EQ( sum[1], 0 );
    ASSERT_EQ( carry, 1 );
}
