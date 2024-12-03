cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

add_library(crypto-integer)

target_sources(crypto-integer
    PUBLIC FILE_SET all_my_modules TYPE CXX_MODULES FILES
    src/main/ixx/integer.ixx
)

add_executable(crypto-integer-test)

target_sources(crypto-integer-test
    PRIVATE FILE_SET all_my_modules TYPE CXX_MODULES FILES
        src/test/ixx/test.ixx
    PRIVATE
        src/test/cxx/integer_2n.cxx
        src/test/cxx/integer_2n_difference.cxx
        src/test/cxx/integer_2n_product.cxx
        src/test/cxx/integer_2n_sum.cxx
        src/test/cxx/main.cxx
)

target_link_libraries(crypto-integer-test crypto-integer GTest::gmock)
