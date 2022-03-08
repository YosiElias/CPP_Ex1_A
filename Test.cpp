#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good output only chars") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
}

TEST_CASE("Good output with spaces") {
	CHECK((mat(9, 7, '@', '*')) == ("@@@@@@@@@\n"
                                    "@*******@\n"
                                    "@*@@@@@*@\n"
                                    "@*@***@*@\n"
                                    "@*@@@@@*@\n"
                                    "@*******@\n"
                                    "@@@@@@@@@"));
}

TEST_CASE("CHECK THROWS") {
   CHECK_THROWS(mat(10, 5, '$', '%'));
}

TEST_CASE("Bad input - zero") {
	CHECK_THROWS(mat(0, 5, '$', '%'));
}

TEST_CASE("Bad input - char") {
	CHECK_THROWS(mat(3, 5, 'k', '%'));
}

TEST_CASE("Bad input - even") {
	CHECK_THROWS(mat(2, 7, '$', '%'));
}

TEST_CASE("Good output 3X3") {
	CHECK(mat(3, 3, '0', '1') ==    "000\n"
                                    "010\n"
                                    "000");
}

TEST_CASE("Good output 5X1") {
	CHECK(mat(5, 1, '0', '1') == "01010");
}

TEST_CASE("Good output 1X1") {
	CHECK(mat(1, 1, '0', '1') == "0");
}

TEST_CASE("Good output - not flips over") {
	CHECK(mat(3, 5, '0', '1') !=    "111\n"
                                    "101\n"
                                    "101\n"
                                    "101\n"
                                    "111");
}

TEST_CASE("Good output - big output") {
	CHECK(mat(9, 7, '0', '1') ==    "000000000\n"
                                    "011111110\n"
                                    "010000010\n"
                                    "010111010\n"
                                    "010000010\n"
                                    "011111110\n"
                                    "000000000");
}

TEST_CASE("Bad output - big output without \n") {
	CHECK(mat(9, 7, '0', '1') !=    "000000000"
                                    "011111110"
                                    "010000010"
                                    "010111010"
                                    "010000010"
                                    "011111110"
                                    "000000000");
}

TEST_CASE("Good output - 1X7") {
	CHECK(mat(1, 7, '0', '1') ==    "0\n"
                                    "1\n"
                                    "0\n"
                                    "1\n"
                                    "0\n"
                                    "1\n"
                                    "0");
}

TEST_CASE("Good output - 11X1") {
	CHECK(mat(11, 1, '0', '1') ==  "01010101010");
}

TEST_CASE("Bad output - \n\n") {
	CHECK((mat(9, 7, '@', '*')) != ("@@@@@@@@@\n"
                                    "@*******@\n"
                                    "@*@@@@@*@\n"
                                    "@*@***@*@\n"
                                    "@*@@@@@*@\n\n"
                                    "@*******@\n"
                                    "@@@@@@@@@"));
}

TEST_CASE("Bad output - \n\n") {
	CHECK((mat(9, 7, '@', '*')) != ("@@@@@@@@@\n"
                                    "@*******@\n"
                                    "@*@@@@@*@\n"
                                    "@*@***@*@\n"
                                    "@*@@@@@*@\n\n"
                                    "@*******@\n"
                                    "@@@@@@@@@"));
}

TEST_CASE("Bad output - extra space") {
	CHECK((mat(9, 7, '@', '*')) != ("@@@@@@@@@\n"
                                    "@*******@\n"
                                    "@*@@@@@*@\n"
                                    "@*@** *@*@\n"
                                    "@*@@@@@*@\n"
                                    "@*******@\n"
                                    "@@@@@@@@@"));
}

TEST_CASE("Good output - :)") {
	CHECK(mat(3, 3, ':', ')') ==    ":::\n"
                                    ":):\n"
                                    ":::");
}

TEST_CASE("Bad input - '\n' as char") {
	CHECK_THROWS(mat(1, 3, '\n', '%'));   //Todo: check if legal
}

TEST_CASE("Bad input - space char") {
	CHECK_THROWS(mat(5, 7, ' ', '@'));   //Todo: check if legal
}

TEST_CASE("Bad input - same char") {
	CHECK_THROWS(mat(3, 9, '%', '%'));   //Todo: check if legal !
}

