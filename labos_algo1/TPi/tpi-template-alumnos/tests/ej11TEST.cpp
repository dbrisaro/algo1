#include "gtest/gtest.h"
#include "../src/ejercicios.h"

TEST(filtradoMediana, senialDesordenada) {
    int prof = 16;
    int freq = 10;
    int r = 2;

    senial s = {54, 23, -65, -102, 34, 71, -35, 77, 13, -46};

    filtradoMediana(s, r, prof, freq);
    senial esperada = {54, 23, 23, 23, -35, 34, 34, 13, 13, -46};

    EXPECT_EQ(esperada, s);
}
