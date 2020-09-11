#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(esReunionValida, reunionNoCuadrada) {
    int prof = 8;
    int freq = 10;

    senial Sig1 = { 17, -128, 128 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig2 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig3 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19};

	reunion reunion1= {make_pair(Sig1,0), make_pair(Sig2, 1), make_pair(Sig3, 2)};

    EXPECT_FALSE(esReunionValida(reunion1,prof,freq));
}

TEST(esReunionValida, matrizPeroNoReunionValida) {
    int prof = 8;
    int freq = 10;

    // Se va de rango en sig1 3ra muestra: 128.
    senial Sig1 = { 17, -128, 128 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig2 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig3 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};

    reunion reunion2= {make_pair(Sig1,0), make_pair(Sig2, 1), make_pair(Sig3, 2)};

    EXPECT_FALSE(esReunionValida(reunion2,prof,freq));
}

TEST(esReunionValida, esReunionVali) {
    int prof = 8;
    int freq = 10;

    senial Sig1 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig2 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  20, -18};
    senial Sig3 = { 17, -128, 127 , 18,  15, -16, 0, 17, -21,  21, -18};

    reunion reunion3= {make_pair(Sig1,0), make_pair(Sig2, 1), make_pair(Sig3, 2)};

    EXPECT_TRUE(esReunionValida(reunion3,prof,freq));
}

TEST(esReunionValida, reunionValida) {
    int prof = 8;
    int freq = 10;

    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};

    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};

    EXPECT_TRUE(esReunionValida(reunion,prof,freq));
}