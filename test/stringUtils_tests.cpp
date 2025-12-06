#include "stringUtils.h"

#include <gtest/gtest.h>

#include <stdexcept>

namespace string = advent::utility::string;

TEST(split_byString, nominal) {
    // ARRANGE
    std::string source{"bananac++orangec++grape"};
    std::string delimiter{"c++"};

    // ACT
    auto result = string::split(source, delimiter);

    // ASSERT
    EXPECT_EQ(3, result.size());

    if (3 != result.size())
        return;

    EXPECT_STREQ("banana", result[0].c_str());
    EXPECT_STREQ("orange", result[1].c_str());
    EXPECT_STREQ("grape", result[2].c_str());
}

TEST(split_byString, nominal_alt) {
    // ARRANGE
    std::string source{"trollhumanorchumantaurenhumanundead"};
    std::string delimiter{"human"};

    // ACT
    auto result = string::split(source, delimiter);

    // ASSERT
    EXPECT_EQ(4, result.size());

    if (4 != result.size())
        return;

    EXPECT_STREQ("troll", result[0].c_str());
    EXPECT_STREQ("orc", result[1].c_str());
    EXPECT_STREQ("tauren", result[2].c_str());
    EXPECT_STREQ("undead", result[3].c_str());
}

TEST(split_byString, nominalFaced) {
    // ARRANGE
    std::string source{"c++bananac++orangec++grapec++"};
    std::string delimiter{"c++"};

    // ACT
    auto split = string::split(source, delimiter);

    // ASSERT
    EXPECT_EQ(5, split.size());

    for (const auto& e : split) {
        std::cout << "'" << e << "'" << "\n";
    }

    if (5 != split.size())
        return;

    EXPECT_STREQ("", split[0].c_str());
    EXPECT_STREQ("banana", split[1].c_str());
    EXPECT_STREQ("orange", split[2].c_str());
    EXPECT_STREQ("grape", split[3].c_str());
    EXPECT_STREQ("", split[4].c_str());
}

TEST(split_byChar, nominal) {
    // ARRANGE
    std::string source{"bananacorangecgrape"};
    char delimiter{'c'};

    // ACT
    auto result = string::split(source, delimiter);

    // ASSERT
    EXPECT_EQ(3, result.size());

    if (3 != result.size())
        return;

    EXPECT_STREQ("banana", result[0].c_str());
    EXPECT_STREQ("orange", result[1].c_str());
    EXPECT_STREQ("grape", result[2].c_str());
}

TEST(split_byChar, nominal_alt) {
    // ARRANGE
    std::string source{"trollhorchtaurenhundead"};
    char delimiter{'h'};

    // ACT
    auto result = string::split(source, delimiter);

    // ASSERT
    EXPECT_EQ(4, result.size());

    if (4 != result.size())
        return;

    EXPECT_STREQ("troll", result[0].c_str());
    EXPECT_STREQ("orc", result[1].c_str());
    EXPECT_STREQ("tauren", result[2].c_str());
    EXPECT_STREQ("undead", result[3].c_str());
}

TEST(equalSubStrsOfLength, nominal) {
    // ARRANGE
    std::string source{"bananac++orangec++grape"};
    std::size_t length1{5};
    std::size_t length2{3};

    // ACT
    auto result1 = string::equalSubStrsOfLength(source, length1);
    auto result2 = string::equalSubStrsOfLength(source, length2);

    // ASSERT
    EXPECT_EQ(4, result1.size());

    if (4 != result1.size())
        return;

    EXPECT_STREQ("banan", result1[0].c_str());
    EXPECT_STREQ("ac++o", result1[1].c_str());
    EXPECT_STREQ("range", result1[2].c_str());
    EXPECT_STREQ("c++gr", result1[3].c_str());

    EXPECT_EQ(7, result2.size());

    if (7 != result2.size())
        return;

    EXPECT_STREQ("ban", result2[0].c_str());
    EXPECT_STREQ("ana", result2[1].c_str());
    EXPECT_STREQ("c++", result2[2].c_str());
    EXPECT_STREQ("ora", result2[3].c_str());
    EXPECT_STREQ("nge", result2[4].c_str());
    EXPECT_STREQ("c++", result2[5].c_str());
    EXPECT_STREQ("gra", result2[6].c_str());
}

TEST(parseToIntArray, nominal) {
    // implicitly tests convertToIntArray
    // ARRANGE
    std::string source{"1, 2, 3, 4"};
    std::string delimiter{","};

    // ACT
    auto result = string::parseToIntArray(source, delimiter);

    // ASSERT
    EXPECT_EQ(4, result.size());

    if (4 != result.size())
        return;

    EXPECT_EQ(1, result[0]);
    EXPECT_EQ(2, result[1]);
    EXPECT_EQ(3, result[2]);
    EXPECT_EQ(4, result[3]);
}

TEST(parseToIntArray, nominal_alt) {
    // implicitly tests convertToIntArray
    // ARRANGE
    std::string source{"17-13-11"};
    std::string delimiter{"-"};

    // ACT
    auto result = string::parseToIntArray(source, delimiter);

    // ASSERT
    EXPECT_EQ(3, result.size());

    if (3 != result.size())
        return;

    EXPECT_EQ(17, result[0]);
    EXPECT_EQ(13, result[1]);
    EXPECT_EQ(11, result[2]);
}

TEST(leadCharMatches, nominal) {
    // ARRANGE
    std::string target{"aaabcde"};
    char c{'a'};
    std::size_t count1 = 2;
    std::size_t count2 = 3;
    std::size_t count3 = 4;

    // ACT
    auto result1 = string::leadCharMatches(target, c, count1);
    auto result2 = string::leadCharMatches(target, c, count2);
    auto result3 = string::leadCharMatches(target, c, count3);

    // ASSERT
    EXPECT_TRUE(result1);
    EXPECT_FALSE(result2);
    EXPECT_FALSE(result3);
}

TEST(leadCharMatches, nominal_alt) {
    // ARRANGE
    std::string target{"banana"};
    char c{'b'};
    std::size_t count1 = 0;
    std::size_t count2 = 1;
    std::size_t count3 = 2;

    // ACT
    auto result1 = string::leadCharMatches(target, c, count1);
    auto result2 = string::leadCharMatches(target, c, count2);
    auto result3 = string::leadCharMatches(target, c, count3);

    // ASSERT
    EXPECT_TRUE(result1);
    EXPECT_FALSE(result2);
    EXPECT_FALSE(result3);
}

TEST(leadCharMatches, not_any) {
    // ARRANGE
    std::string target{"banana"};
    char c{'a'};
    std::size_t count1{0};
    std::size_t count2{1};
    std::size_t count3{2};

    // ACT
    auto result1 = string::leadCharMatches(target, c, count1);
    auto result2 = string::leadCharMatches(target, c, count2);
    auto result3 = string::leadCharMatches(target, c, count3);

    // ASSERT
    EXPECT_FALSE(result1);
    EXPECT_FALSE(result2);
    EXPECT_FALSE(result3);
}

TEST(leadCharMatches, too_short) {
    // ARRANGE
    std::string target{"banana"};
    char c{'b'};
    std::size_t count{7};

    // ACT
    auto result = string::leadCharMatches(target, c, count);

    // ASSERT
    EXPECT_FALSE(result);
}

TEST(leadCharMatches, too_short_alt) {
    // ARRANGE
    std::string target{"flan"};
    char c{'f'};
    std::size_t count{4};

    // ACT
    auto result = string::leadCharMatches(target, c, count);

    // ASSERT
    EXPECT_FALSE(result);
}

TEST(replace_single, nominal) {
    // ARRANGE
    std::string source{"c++bananac++orangec++grapec++"};
    std::string target{"c++"};
    std::string replacement{"++c"};

    std::string expectedResult{"++cbanana++corange++cgrape++c"};

    // ACT
    auto result = string::replace(source, target, replacement);

    // ASSERT
    EXPECT_STREQ(expectedResult.c_str(), result.c_str());
}

TEST(replace_multiple, nominal) {
    // ARRANGE
    std::string source{"trollhumanorchumantaurenhumanundead"};
    std::vector<std::string> targets{"troll", "orc", "tauren", "undead"};
    std::vector<std::string> replacements{"horde1", "horde2", "horde3",
                                          "horde4"};

    std::string expectedResult{"horde1humanhorde2humanhorde3humanhorde4"};

    // ACT
    auto result = string::replace(source, targets, replacements);

    // ASSERT
    EXPECT_STREQ(expectedResult.c_str(), result.c_str());
}

TEST(replace_multiple, nominal_alt) {
    // ARRANGE
    std::string source{"c++bananac++orangec++grapec++"};
    std::vector<std::string> targets{"banana", "orange", "grape"};
    std::vector<std::string> replacements{"yellow", "well,orange,innit",
                                          "purple"};

    std::string expectedResult{"c++yellowc++well,orange,innitc++purplec++"};

    // ACT
    auto result = string::replace(source, targets, replacements);

    // ASSERT
    EXPECT_STREQ(expectedResult.c_str(), result.c_str());
}

TEST(replace_multiple, mismatchLength) {
    // ARRANGE
    std::string source{"c++bananac++orangec++grapec++"};
    std::vector<std::string> targets{"banana", "orange", "grape"};
    std::vector<std::string> replacements{"yellow", "purple"};

    std::string expectedResult{"c++yellowc++well,orange,innitc++purplec++"};

    // ACT and ASSERT
    EXPECT_THROW(string::replace(source, targets, replacements),
                 std::invalid_argument);
}

TEST(replace_multiple, mismatchLength_alt) {
    // ARRANGE
    std::string source{"c++bananac++orangec++grapec++"};
    std::vector<std::string> targets{"banana", "grape"};
    std::vector<std::string> replacements{"yellow", "well,orange,innit",
                                          "purple"};

    std::string expectedResult{"c++yellowc++well,orange,innitc++purplec++"};

    // ACT and ASSERT
    EXPECT_THROW(string::replace(source, targets, replacements),
                 std::invalid_argument);
}
