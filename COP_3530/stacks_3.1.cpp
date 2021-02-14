#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

class Node
{
public:
    int data;
    Node* next;
    Node(int val) {data = val; next = nullptr;}
    Node(int val, Node* node) {data = val; next = node;}
};

class Stack_LL
{
private:
    Node* top = nullptr;

public:
    Stack_LL();
    ~Stack_LL();

    bool isEmpty() const;
    void push(int newItem);
    void pop();
    int peek() const;
};

Stack_LL::Stack_LL()
{}

Stack_LL::~Stack_LL()
{
    while(top)
    {
        auto next = top->next;
        delete top;
        top = next;
    }
}

bool Stack_LL::isEmpty() const
{
    return top == nullptr;
}

void Stack_LL::push(int newItem)
{
    auto currentTop = top;
    top = new Node(newItem);
    top->next = currentTop;
}

void Stack_LL::pop()
{
    if (top)
    {
        auto p = top;
        top = p->next;
        delete p;
    }
}

int Stack_LL::peek() const
{
    if (top)
        return top->data;
    return 0;
}

TEST_CASE("Test stack basic functionality")
{
    Stack_LL stack;
    REQUIRE(stack.isEmpty());
    stack.push(1);
    REQUIRE_FALSE(stack.isEmpty());
    REQUIRE(stack.peek() == 1);
    REQUIRE_NOTHROW(stack.pop());
    REQUIRE(stack.isEmpty());
    REQUIRE_NOTHROW(stack.pop());
    REQUIRE(stack.isEmpty());
    REQUIRE_NOTHROW(stack.peek());

    stack.push(1);
    stack.push(2);
    stack.push(3);
    REQUIRE(stack.peek() == 3);
    REQUIRE_FALSE(stack.isEmpty());
    REQUIRE_NOTHROW(stack.pop());
    REQUIRE(stack.peek() == 2);
    REQUIRE_FALSE(stack.isEmpty());
    REQUIRE_NOTHROW(stack.pop());
    REQUIRE(stack.peek() == 1);
    REQUIRE_FALSE(stack.isEmpty());
    REQUIRE_NOTHROW(stack.pop());
    REQUIRE(stack.isEmpty());
}
