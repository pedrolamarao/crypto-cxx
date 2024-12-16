// Copyright (C) 2024 Pedro Lamarão <pedro.lamarao@gmail.com>. All rights reserved.

#include <gtest/gtest.h>

import br.dev.pedrolamarao.crypto.integer;
import br.dev.pedrolamarao.crypto.integer.test;

using namespace br::dev::pedrolamarao::crypto::integer;
using namespace std;

TYPED_TEST(integer_2n_test,is_zero_equisized_1_0)
{
    auto x = TypeParam::create(1);
    x[0] = 0;

    auto z = is_zero(x);

    ASSERT_EQ( z, 1 );
}


TYPED_TEST(integer_2n_test,is_zero_equisized_1_1)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto z = is_zero(x);

    ASSERT_EQ( z, 0 );
}

TYPED_TEST(integer_2n_test,is_zero_equisized_1_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(1);
    x[0] = max;

    auto z = is_zero(x);

    ASSERT_EQ( z, 0 );
}

TYPED_TEST(integer_2n_test,is_zero_equisized_2_0)
{
    auto x = TypeParam::create(2);
    x[0] = 0;
    x[1] = 0;

    auto z = is_zero(x);

    ASSERT_EQ( z, 1 );
}
TYPED_TEST(integer_2n_test,is_zero_equisized_2_1)
{
    auto x = TypeParam::create(2);
    x[0] = 1;
    x[1] = 0;

    auto z = is_zero(x);

    ASSERT_EQ( z, 0 );
}

TYPED_TEST(integer_2n_test,is_zero_equisized_2_max)
{
    using unit = typename TypeParam::unit;
    unit max = unit(-1); // guaranteed by C++

    auto x = TypeParam::create(2);
    x[0] = max;
    x[1] = max;

    auto z = is_zero(x);

    ASSERT_EQ( z, 0 );
}
