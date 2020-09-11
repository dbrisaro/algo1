#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(silencios, silenciosTresSilenciosSeparados){
    int prof = 32;
    int freq = 10;
    int umbral = 80;

    senial s = {5, -3, 2, 1, 66, 734, -1803, -551, -19, 27, 396, 231, 32, 33, 14};

    vector<pair<int, int>> intervalos = silencios(s, prof, freq, umbral);
    vector<pair<int, int>> esperado = {make_pair(0, 4), make_pair(8, 9), make_pair(12, 14)};

    EXPECT_EQ(intervalos, esperado);
}

TEST(silencios, sinSilencios){
    int prof = 32;
    int freq = 10;
    int umbral = 80;

    // Como consideramos un intervalo de silencio, un intervalo con al menos 2 muestras,
    // el 20 no se considera como tal.
    senial s = {85, -83, 20, 88, 100, 86, 734, -1803, -551, -90, 127, 396, 231, 132, 133, 140};

    vector<pair<int, int>> intervalos = silencios(s, prof, freq, umbral);
    vector<pair<int, int>> esperado = {};

    EXPECT_EQ(intervalos, esperado);
}

TEST(silencios, TodoSilencio){
    int prof = 32;
    int freq = 10;
    int umbral = 36;

    senial s = {5, -3, 2, 1, 6, 23, -18, -15, -19, 27, 35, 31, 32, 33, 14};

    vector<pair<int, int>> intervalos = silencios(s, prof, freq, umbral);
    vector<pair<int, int>> esperado = {make_pair(0, 14)};

    EXPECT_EQ(intervalos, esperado);
}
