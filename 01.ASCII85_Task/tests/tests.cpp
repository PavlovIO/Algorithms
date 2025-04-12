/* Ilya Pavlov st129535@student.spbu.ru
	Lab-work-2
*/
#include "ascii85.h"
#include<gtest/gtest.h>

// Тест кодирования строки "Hello"
TEST(Ascii85Test, EncodeHello)
{
    std::string input = "Hello";
    std::string expected_start = "87cURDZ"; // ASCII85 код "Hello" начинается с этого

    std::string result = ascii85(input, "-e", false);
    ASSERT_TRUE(result.rfind(expected_start, 0) == 0);  // Проверяем, что результат начинается с expected_start
    ASSERT_TRUE(result.ends_with("~>")); // Все ASCII85 строки должны заканчиваться ~>
}

// Тест декодирования обратно
TEST(Ascii85Test, DecodeHello)
{
    std::string result = ascii85("87cURD]i,\"Ebo7~>", "-d", false);
    ASSERT_EQ(result, "Hello World");
}

// Тест пустой строки
TEST(Ascii85Test, EmptyString)
{
    std::string input = "";
    std::string encoded = ascii85(input, "-e", false);
    std::string decoded = ascii85(encoded, "-d", false);

    ASSERT_EQ(decoded, input);
}

// Невалидный символ в декодировании
TEST(Ascii85Test, InvalidCharDecode)
{
    std::string input = "87cURw~>";
    std::string result = ascii85(input, "-d", false);
    ASSERT_EQ(result, "");
}

// Тест кодирования строки с картонным вводом
TEST(Ascii85Test, EncodeHelloWithMockInput)
{
    std::string input_str = "Hi my name is Ilya";
    std::istringstream input(input_str);
    std::ostringstream output;

    encoder_ascii_85(input, output);

    std::string result = output.str();

    std::string expected_start = "8802`Gp%!5D.Oi(F!+%jH!p";
    ASSERT_TRUE(result.rfind(expected_start, 0) == 0);
    ASSERT_TRUE(result.ends_with("~>"));
}

// Тест декодирования строки с картонным вводом
TEST(Ascii85Test, DecodeHelloWithMockInput)
{
    std::string input_str = "87cURD]j7BEbo80~>";
    std::istringstream input(input_str);
    std::ostringstream output;

    decoder_ascii_85(input, output);

    std::string result = output.str();

    ASSERT_EQ(result, "Hello world!");
}

// Тест пустой строки
TEST(Ascii85Test, EmptyStringWithMockInput)
{
    std::string input_str = "";
    std::istringstream input(input_str);
    std::ostringstream output;

    encoder_ascii_85(input, output);
    std::string encoded = output.str();

    std::istringstream decode_input(encoded);
    std::ostringstream decode_output;

    decoder_ascii_85(decode_input, decode_output);
    std::string decoded = decode_output.str();

    ASSERT_EQ(decoded, input_str);
}

// Тест с ошибочным символом в ASCII85
TEST(Ascii85Test, InvalidCharWithMockInput)
{
    std::string input_str = "87cURw~>";
    std::istringstream input(input_str);
    std::ostringstream output;

    ASSERT_EQ(decoder_ascii_85(input, output), 1);
}

