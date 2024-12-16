// Copyright (C) 2024 Pedro Lamarão <pedro.lamarao@gmail.com>. All rights reserved.

#include <gtest/gtest.h>

import br.dev.pedrolamarao.crypto.integer;
import br.dev.pedrolamarao.crypto.integer.test;

using namespace br::dev::pedrolamarao::crypto::integer;
using namespace std;

TYPED_TEST(integer_2n_test,remain_1_1)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto r = remain(x,y);

    ASSERT_EQ( r.digits(), 1 );
    ASSERT_EQ( r[0], 0 );
}

TYPED_TEST(integer_2n_test,remain_1_2)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 2;

    auto r = remain(x,y);

    ASSERT_EQ( r.digits(), 1 );
    ASSERT_EQ( r[0], 1 );
}


TYPED_TEST(integer_2n_test,remain_1_3)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam::create(1);
    y[0] = 3;

    auto r = remain(x,y);

    ASSERT_EQ( r.digits(), 1 );
    ASSERT_EQ( r[0], 1 );
}

TYPED_TEST(integer_2n_test,remain_2_1)
{
    auto x = TypeParam::create(1);
    x[0] = 2;

    auto y = TypeParam::create(1);
    y[0] = 1;

    auto r = remain(x,y);

    ASSERT_EQ( r.digits(), 1 );
    ASSERT_EQ( r[0], 0 );
}

TYPED_TEST(integer_2n_test,remain_2_2)
{
    auto x = TypeParam::create(1);
    x[0] = 2;

    auto y = TypeParam::create(1);
    y[0] = 2;

    auto r = remain(x,y);

    ASSERT_EQ( r.digits(), 1 );
    ASSERT_EQ( r[0], 0 );
}

TYPED_TEST(integer_2n_test,remain_2_3)
{
    auto x = TypeParam::create(1);
    x[0] = 2;

    auto y = TypeParam::create(1);
    y[0] = 3;

    auto r = remain(x,y);

    ASSERT_EQ( r.digits(), 1 );
    ASSERT_EQ( r[0], 2 );
}
