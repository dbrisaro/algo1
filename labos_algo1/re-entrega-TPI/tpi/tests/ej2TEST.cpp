#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(seEnojo, checkForSubseqOfMinSizeTwoTimesFreq) {
    int prof = 8;
    int freq = 10;
    int thresh = 65;

    senial fstSig = { 17,   32,   80,   85,   99,   62,    7,  -55, -107, -101,  -88, -26,
    -3,   52,   62,   99,   89,   67,    7,  -61,  -97, -115, -71,  -45,   17};

    EXPECT_TRUE(seEnojo(fstSig, thresh, prof, freq));
}

TEST(seEnojo, secuenciaNoSeEnojo) {
    int prof = 8;
    int freq = 10;
    int thresh = 65;

    senial fstSig = { 17,   32,   80,   25,   99,   62,    7,  -55, -17, -101,  -8, -26,
                      -3,   52,   62,   99,   58,   67,    7,  -61,  -97, -15, -71,  -45,   17};

    EXPECT_FALSE(seEnojo(fstSig, thresh, prof, freq));
}

TEST(seEnojo, tonoMayorUmbralValorFlotantePor1) {
    int prof = 8;
    int freq = 10;
    int thresh = 50;

    senial sndSig = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                 100, 100, 100, 100, 100, 100, 100, 100, 100, 101,
                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    EXPECT_TRUE(seEnojo(sndSig, thresh, prof,freq));
}

TEST(seEnojo, justo2Seg) {
    int prof = 8;
    int freq = 10;
    int thresh = 50;

    senial sndSig = {-100, -100, -100, -100, -100, -100, -100, -100, -100, -100,
                     -100, -100, -100, -100, -100, -100, -100, -100, -100, -100};

    EXPECT_FALSE(seEnojo(sndSig, thresh, prof,freq));
}
