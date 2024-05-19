#include "../ext/googletest/googletest/include/gtest/gtest.h"
#include "../include/extraction.h"

TEST(Contains, TestTrue)
{
    const char *str = "abcdefghijklmnopqrstuvwxyz";
    EXPECT_TRUE(contains((char *)str, str + 26, 'b'));
    EXPECT_TRUE(contains((char *)str + 5, str + 20, 'q'));
    EXPECT_TRUE(contains((char *)str + 10, str + 15, 'l'));
}

TEST(Contains, TestFalse)
{
    const char *str = "abcdefghijklmnopqrstuvwxyz";
    EXPECT_FALSE(contains((char *)str, str + 24, 'z'));
    EXPECT_FALSE(contains((char *)str + 5, str + 20, 'x'));
    EXPECT_FALSE(contains((char *)str + 10, str + 15, 'a'));
}

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