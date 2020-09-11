#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(acelerar, senialLargoImpar) {
    int prof = 16;
    int freq = 10;

    senial sig = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
                   -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
                   -45,  -60,    9};

    reunion reunion_out = {make_pair(sig,0)};
    senial sig_res={43, 103, 59, -44, -104, -60, 43, 103, 59, -44, -104, -60};
    reunion res = { make_pair(sig_res,0) };

    acelerar(reunion_out,prof,freq);

    EXPECT_EQ(res, reunion_out);
}

TEST(acelerar, senialLargoPar) {
    int prof = 16;
    int freq = 10;

    senial sig = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
                   -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
                   -45,  -60};

    reunion reunion_out = {make_pair(sig,0)};
    senial sig_res={43, 103, 59, -44, -104, -60, 43, 103, 59, -44, -104, -60};
    reunion res = { make_pair(sig_res,0) };

    acelerar(reunion_out,prof,freq);

    EXPECT_EQ(res, reunion_out);
}
