#include "gtest/gtest.h"
#include "../src/ejercicios.h"

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

TEST(seEnojoTEST, secuenciaEnojoBorde){
    senial fstSig = { 17,   32,   80,   85,   99,   62,    7,  -55, -17, -101,  -88, -26,
                      -3,   52,   62,   99,   89,   67,    7,  -61,  -97,  -71,  -45, -115,  107};
    int prof = 12;
    int freq = 10;
    int thresh = 4;

    EXPECT_TRUE(seEnojo(fstSig, thresh, prof, freq));
}
