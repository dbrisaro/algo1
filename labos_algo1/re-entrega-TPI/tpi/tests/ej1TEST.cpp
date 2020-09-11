#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(esSenial, senialEsValida) {
    int prof = 8;
    int freq = 10;
    
    senial sig = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
        -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
        -45,  -60,    9};
    
    EXPECT_TRUE(esSenial(sig,prof,freq));
}

TEST(esSenial, profNoEsValida) {
    int prof = 64;
    int freq = 10;

    senial sig = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
                   -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
                   -45,  -60,    9};

    EXPECT_FALSE(esSenial(sig,prof,freq));
}

TEST(esSenial, freqInvalida) {
    int prof = 32;
    int freq = 3;

    senial sig = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
                   -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
                   -45,  -60,    9};

    EXPECT_FALSE(esSenial(sig,prof,freq));
}

TEST(esSenial, senialVacia) {
    int prof = 8;
    int freq = 10;

    senial sig = {};

    EXPECT_FALSE(esSenial(sig,prof,freq));
}

TEST(esSenial, senialPositiva) {
    int prof = 8;
    int freq = 10;

    senial sig = { 9,   43,   54,  103,   44,   59,  10,  44,  55, 104,  45,
                   60,    9,   43,   54,  103,   44,   59,  10,  44,  55, 104,
                   45,  60,    9};

    EXPECT_TRUE(esSenial(sig,prof,freq));
}

TEST(esSenial, senialTodaNegativa) {
    int prof = 8;
    int freq = 10;

    senial sig = { -9,   -43,   -54,  -103,   -44,   -59,  -10,  -44,  -55, -104,  -45,
                   -60,    -9,   -43,   -54,  -103,   -44,   -59,  -10,  -44,  -55, -104,
                   -45,  -60,    -9};

    EXPECT_TRUE(esSenial(sig,prof,freq));
}

TEST(esSenial, senialChica) {
    int prof = 8;
    int freq = 10;

    senial sig = { 9, 43, 54, 103, 44, 59, -10, -60, -45};

    EXPECT_FALSE(esSenial(sig,prof,freq));
}