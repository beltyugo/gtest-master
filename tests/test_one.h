#ifndef TEST_ONE_H
#define TEST_ONE_H

extern "C" {
#include "common.h"
}

TEST(test_one_h, one)
{
    text txt = create_text();
    showlengths(txt);
    SUCCEED();
}

#endif // TEST_ONE_H
