#include "../ext/googletest/googletest/include/gtest/gtest.h"
#include "../include/extraction.h"

TEST(Extraction, TestEmptyString)
{
    EXPECT_EQ(extraction(""), "");
}

TEST(Extraction, TestOneLetter)
{
    EXPECT_EQ(extraction("b"), "b");
}

TEST(Extraction, TestSameLetter)
{
    EXPECT_EQ(extraction("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), "a");
}

TEST(Extraction, TestOtherLetterAtFirst)
{
    EXPECT_EQ(extraction("abbbbbbbbbbbbbbbbbb"), "ab");
}

TEST(Extraction, TestOtherLetterAtLast)
{
    EXPECT_EQ(extraction("bbbbbbbbbbbbbbbbbc"), "bc");
}

TEST(Extraction, TestOtherLetterInMiddle)
{
    EXPECT_EQ(extraction("bbbbbbbbcddddddddd"), "bcd");
}

TEST(Extraction, TestRandomString)
{
    EXPECT_EQ(extraction("aaaaaaaaaaaabhhjkgbunmppgggggggggggggggggggg"), "hjkgbunmp");
}