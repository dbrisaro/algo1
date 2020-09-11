#include "gtest/gtest.h"
#include "../ejercicios.h"

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

TEST(reconstruir, VariosCeros) {
    int prof = 8;
    int freq = 10;

    senial s = {50, 24, 0, 0, 0, 1, -17, -60, 0, -55, -77,
                -80, 0, -91};
    senial rec = reconstruir(s, prof, freq);
    senial esperada = {50, 24, 12, 12, 12, 1, -17, -60, -57, -55, -77,
                       -80, -85, -91};

    EXPECT_EQ(rec, esperada);
}

TEST(reconstruir, sinusoidal) {
    int prof = 8;
    int freq = 10;

    senial s = {50, 24, 0, -30, 1, -17, 60, 0, -55, -77,
                -80, 0, -91};
    senial rec = reconstruir(s, prof, freq);
    senial esperada = {50, 24, 0, -30, 1, -17, 60, 0, -55, -77,
                       -80, -85, -91};

    EXPECT_EQ(rec, esperada);
}

TEST(reconstruir, reconstruirValidos) {

    int prof = 8;
    int freq = 10;

    senial hablante1 = {1, 3, -3, 4, 6, 0, 0, -8, 9, -15};

    senial rec = reconstruir(hablante1, prof, freq);
    senial esperada = {1, 3, -3, 4, 6, -1, -1, -8, 9, -15};

    EXPECT_EQ(rec, esperada);
}