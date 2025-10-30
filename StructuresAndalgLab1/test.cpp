#define CATCH_CONFIG_MAIN
#define _CRT_SECURE_NO_WARNINGS

#include "catch.hpp"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <direct.h>

#include "array.h"
#include "method_c.h"
#include "method_fille.h"

using namespace std;

string read_file() {
    char res[256] = "";
    FILE* in = fopen("Laba1/output.txt", "r");
    if (in && fgets(res, 256, in) != NULL) {
        fclose(in);
    }
    return string(res);
}

void write_file(const char str[]) {
    _mkdir("Laba1");
    FILE* out = fopen("Laba1/input.txt", "w");
    if (!out) return;
    fputs(str, out);
    fclose(out);
}

TEST_CASE("Array: Empty string", "[array_string]") {
    char str[256] = "";
    process_string(str);
    REQUIRE(strcmp(str, "") == 0);
}

TEST_CASE("Array: Single space", "[array_string]") {
    char str[256] = " ";
    process_string(str);
    REQUIRE(strcmp(str, "") == 0);
}

TEST_CASE("Array: No spaces", "[array_string]") {
    char str[256] = "Helloworld";
    process_string(str);
    REQUIRE(strcmp(str, "Helloworld") == 0);
}

TEST_CASE("Array: Single spaces between words", "[array_string]") {
    char str[256] = "Hello world test";
    process_string(str);
    REQUIRE(strcmp(str, "Helloworldtest") == 0);
}

TEST_CASE("Array: 2-3 consecutive spaces", "[array_string]") {
    char str[256] = "Hello  World   Test";
    process_string(str);
    REQUIRE(strcmp(str, "HelloWorldTest") == 0);
}

TEST_CASE("Array: Exactly 4 consecutive spaces", "[array_string]") {
    char str[256] = "Hello    World";
    process_string(str);
    REQUIRE(strcmp(str, "HelloWorld") == 0);
}

TEST_CASE("Array: 5 consecutive spaces", "[array_string]") {
    char str[256] = "Hello     World";
    process_string(str);
    REQUIRE(strcmp(str, "Hello_World") == 0);
}

TEST_CASE("Array: 6+ consecutive spaces", "[array_string]") {
    char str[256] = "Hello      World";
    process_string(str);
    REQUIRE(strcmp(str, "Hello_World") == 0);
}

TEST_CASE("Array: Multiple space sequences", "[array_string]") {
    char str[256] = "A  B     C   D      E";
    process_string(str);
    REQUIRE(strcmp(str, "AB_CD_E") == 0);
}

TEST_CASE("C String: Empty string", "[c_string]") {
    char str[256] = "";
    process_cstring(str);
    REQUIRE(strcmp(str, "") == 0);
}

TEST_CASE("C String: Single space", "[c_string]") {
    char str[256] = " ";
    process_cstring(str);
    REQUIRE(strcmp(str, "") == 0);
}

TEST_CASE("C String: No spaces", "[c_string]") {
    char str[256] = "Helloworld";
    process_cstring(str);
    REQUIRE(strcmp(str, "Helloworld") == 0);
}

TEST_CASE("C String: Single spaces between words", "[c_string]") {
    char str[256] = "Hello world test";
    process_cstring(str);
    REQUIRE(strcmp(str, "Helloworldtest") == 0);
}

TEST_CASE("C String: 2-3 consecutive spaces", "[c_string]") {
    char str[256] = "Hello  World   Test";
    process_cstring(str);
    REQUIRE(strcmp(str, "HelloWorldTest") == 0);
}

TEST_CASE("C String: Exactly 4 consecutive spaces", "[c_string]") {
    char str[256] = "Hello    World";
    process_cstring(str);
    REQUIRE(strcmp(str, "HelloWorld") == 0);
}

TEST_CASE("C String: 5 consecutive spaces", "[c_string]") {
    char str[256] = "Hello     World";
    process_cstring(str);
    REQUIRE(strcmp(str, "Hello_World") == 0);
}

TEST_CASE("C String: 6+ consecutive spaces", "[c_string]") {
    char str[256] = "Hello      World";
    process_cstring(str);
    REQUIRE(strcmp(str, "Hello_World") == 0);
}

TEST_CASE("C String: Multiple space sequences", "[c_string]") {
    char str[256] = "A  B     C   D      E";
    process_cstring(str);
    REQUIRE(strcmp(str, "AB_CD_E") == 0);
}

TEST_CASE("File: Empty file", "[file_string]") {
    write_file("");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "");
}

TEST_CASE("File: Single space", "[file_string]") {
    write_file(" ");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "");
}

TEST_CASE("File: No spaces", "[file_string]") {
    write_file("Helloworld");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "Helloworld");
}

TEST_CASE("File: Single spaces between words", "[file_string]") {
    write_file("Hello world test");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "Helloworldtest");
}

TEST_CASE("File: 2-3 consecutive spaces", "[file_string]") {
    write_file("Hello  World   Test");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "HelloWorldTest");
}

TEST_CASE("File: Exactly 4 consecutive spaces", "[file_string]") {
    write_file("Hello    World");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "HelloWorld");
}

TEST_CASE("File: 5 consecutive spaces", "[file_string]") {
    write_file("Hello     World");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "Hello_World");
}

TEST_CASE("File: 6+ consecutive spaces", "[file_string]") {
    write_file("Hello      World");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "Hello_World");
}

TEST_CASE("File: Multiple space sequences", "[file_string]") {
    write_file("A  B     C   D      E");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "AB_CD_E");
}