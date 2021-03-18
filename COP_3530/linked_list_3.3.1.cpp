#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

/* Write a function find(Node* node, int valueInput) that starts at the
 * given node and returns the index of the node with the value valueInput.
 * Indices start at 0.  Return -1 if valueInput does not exist.
 */

struct Node
{
    int value;
    Node* next = nullptr;
};

int find(Node* node, int valueInput)
{
    size_t i = 0;
    for(; node && node->value != valueInput; node = node->next) ++i;
    return node ? i : -1;
}

TEST_CASE("Test value search.")
{
    Node d{4};
    Node c{3, &d};
    Node b{2, &c};
    Node a{1, &b};

    REQUIRE(find(&a, 5) == -1);
    REQUIRE(find(&a, 4) == 3);
    REQUIRE(find(&a, 1) == 0);
}
