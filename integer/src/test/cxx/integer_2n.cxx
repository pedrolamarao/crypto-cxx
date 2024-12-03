#include <gtest/gtest.h>

import br.dev.pedrolamarao.crypto.integer;
import br.dev.pedrolamarao.crypto.integer.test;

using namespace br::dev::pedrolamarao::crypto::integer;
using namespace std;

TYPED_TEST(integer_2n_test,copy)
{
    auto x = TypeParam::create(1);
    x[0] = 1;

    auto y = TypeParam(x);

    ASSERT_EQ(x.digits(),y.digits());
    ASSERT_EQ(x[0],y[0]);
}
