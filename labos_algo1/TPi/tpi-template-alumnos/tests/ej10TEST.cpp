#include "gtest/gtest.h"
#include "../src/ejercicios.h"

TEST(reconstruir, faltantesDeUnaMuestra) {
    int prof = 8;
    int freq = 10;

    senial s = {50, 24, 0, 30, 1, -17, -60, 0, -55, -77,
                -80, 0, -91};
    senial rec = reconstruir(s, prof, freq);
    senial esperada = {50, 24, 27, 30, 1, -17, -60, -57, -55, -77, 
                       -80, -85, -91};

    EXPECT_EQ(rec, esperada);
}
