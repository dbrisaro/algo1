#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(ralentizar, unHablanteSenialAscendente) {
    int prof = 16;
    int freq = 10;

    senial sig1={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reunion meet_out = { make_pair(sig1,0 )  };

    senial sig1_res={1, 1, 2, 2, 3, 3, 4, 4, 5, 5,
                     6, 6, 7, 7, 8, 8, 9, 9, 10};

    reunion meet_res = { make_pair(sig1_res,0 ) };

    ralentizar(meet_out,prof,freq);

    EXPECT_EQ(meet_res, meet_out);
}

TEST(ralentizar, senialImpar) {
    int prof = 16;
    int freq = 10;

    senial sig1={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    reunion meet_out = { make_pair(sig1,0 )  };

    senial sig1_res={1, 1, 2, 2, 3, 3, 4, 4, 5, 5,
                     6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11};

    reunion meet_res = { make_pair(sig1_res,0 ) };

    ralentizar(meet_out,prof,freq);

    EXPECT_EQ(meet_res, meet_out);
}
TEST(ralentizar, dosHablantesSenialAscendenteYDescendente) {
    int prof = 16;
    int freq = 10;

    senial sig1={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    senial sig2={ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    reunion meet_out = { make_pair(sig1,0 ), make_pair(sig2,1 )  };

    senial sig1_res={1, 1, 2, 2, 3, 3, 4, 4, 5, 5,
                     6, 6, 7, 7, 8, 8, 9, 9, 10};
    senial sig2_res={10, 9, 9, 8, 8, 7, 7, 6, 6, 5, 5,
                     4, 4, 3, 3, 2, 2, 1, 1};

    reunion meet_res = { make_pair(sig1_res,0 ), make_pair(sig2_res,1 ) };

    ralentizar(meet_out,prof,freq);

    EXPECT_EQ(meet_res, meet_out);
}