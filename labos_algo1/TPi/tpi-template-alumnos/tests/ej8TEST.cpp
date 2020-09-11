#include "gtest/gtest.h"
#include "../src/ejercicios.h"

TEST(silencios, silenciosTresSilenciosSeparados){
    int prof = 32;
    int freq = 10;
    int umbral = 80;

    senial s = {5, -3, 2, 1, 66, 734, -1803, -551, -19, 27, 396, 231, 32, 33, 14};

    vector<pair<int, int>> intervalos = silencios(s, prof, freq, umbral);
    vector<pair<int, int>> esperado = {make_pair(0, 4), make_pair(8, 9), make_pair(12, 14)};

    EXPECT_EQ(intervalos, esperado);
}
