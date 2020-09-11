#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(hablantesSuperpuestos, tresSuperpuestos) {
    int prof = 16;
    int freq = 10;
    int umbral = 12;

    senial s_a = {10, 51, 82, 97, 39, 2, 1, 0, 21, 15, 7};
    senial s_b = {2, 3, 2, -100, -32, -55, -4, -6, -100, -75, 20 };
    senial s_c = {-61, -9, -7, -65, -77, -8, -30, -3, 27, 36, 5};
    pair <senial, hablante> h_a (s_a, 0);
    pair <senial, hablante> h_b (s_b, 1);
    pair <senial, hablante> h_c (s_c, 2);

    reunion r = {h_a, h_b, h_c};

    EXPECT_TRUE(hablantesSuperpuestos(r, prof, freq, umbral));
}

TEST(hablantesSuperpuestos, sinHablantesSuperpuestos) {
    int prof = 16;
    int freq = 10;
    int umbral = 12;

    senial s_a = {10, 11, 2, 7, 9, 2, 1, 0, 21, 15, 17};
    senial s_b = {2, 3, 1, -10, -3, -5, -4, -6, -10, -7, 0 };
    senial s_c = {-13, -9, -7, -5, -77, -18, -3, -3, 7, 6, 5};
    pair <senial, hablante> h_a (s_a, 0);
    pair <senial, hablante> h_b (s_b, 1);
    pair <senial, hablante> h_c (s_c, 2);

    reunion r = {h_a, h_b, h_c};

    EXPECT_FALSE(hablantesSuperpuestos(r, prof, freq, umbral));
}