module;

#include <gtest/gtest.h>

export module br.dev.pedrolamarao.crypto.integer.test;

import br.dev.pedrolamarao.crypto.integer;

export namespace br::dev::pedrolamarao::crypto::integer
{
    template <typename T>
    struct integer_2n_test : testing::Test
    { };

    using integer_2n_types = testing::Types<integer_2n<8>,integer_2n<16>,integer_2n<32>,integer_2n<64>>;

    TYPED_TEST_SUITE(integer_2n_test,integer_2n_types);
}
