#include <QCoreApplication>
#include <iostream>
//
#include <gtest/gtest.h>
#include "mfikeypadparser.h"

struct ParserTest: testing::Test {
    BuildinKeypadParser* parser;
    ParserTest() {
        parser = new BuildinKeypadParser;
    }
    ~ParserTest() {
        delete parser;
    }
};

TEST_F(ParserTest, lengthTest) {
    std::string message = "$MKEY:5\n";
    unsigned long length = message.length();
    EXPECT_EQ( true, parser->checkLength(length) );
}

TEST_F(ParserTest, formatTest) {
    std::string message = "$MKEY:5\n";
    unsigned long length = message.length();
    EXPECT_EQ( true, parser->checkFormat(message, length) );
}

TEST_F(ParserTest, commandTest) {
    std::string message = "$MBRI:5\n";
    std::string commandName = message.substr(1, 4);
    EXPECT_EQ( true, parser->checkCommand(commandName) );
}

TEST_F(ParserTest, keyTest) {
    std::string message = "$MKEY:~1\n";
    unsigned long length = message.length();
    std::string data = message.substr(6, length-7);
    EXPECT_EQ( IdKey::BUILDIN_KEY_2, parser->getKey(data) );
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
