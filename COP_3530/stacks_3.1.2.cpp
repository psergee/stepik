#include <stack>

#define CATCH_CONFIG_MAIN 
#include "Catch2.h"

/*
Write a method bool inLanguage(char* theString) that uses one stack to determine whether theString has the same number of A's as B's. 
If the string contains anything other than A or B (capital A or capital B), return false.
You are allowed to use the Stack from C++ STL Library and you do not need to implement your own Stack.
*/

bool inLanguage(const char* theString)
{
    std::stack<char> characters;
    for (const char* c = theString; *c; ++c)
    {
        if (*c != 'A' && *c != 'B')
            return false;

        if (characters.empty() || characters.top() == *c)
            characters.push(*c);
        else if (characters.top() != *c)
            characters.pop();
    }
    return characters.empty();
}

TEST_CASE("Test inLanguage function")
{
    REQUIRE(inLanguage(""));
    REQUIRE(inLanguage("AB"));
    REQUIRE_FALSE(inLanguage("A"));
    REQUIRE_FALSE(inLanguage("ABA"));
    REQUIRE(inLanguage("BBBAAA"));
    REQUIRE(inLanguage("AAABBB"));
    REQUIRE_FALSE(inLanguage("AAABB"));
    REQUIRE_FALSE(inLanguage("AAABBBC"));
}
