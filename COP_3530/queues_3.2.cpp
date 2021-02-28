#include <array>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

constexpr size_t CAPACITY = 4;

class CircularArrayQueue {

private:
    std::array<int, CAPACITY> circularArray;
    size_t start, end;

public:
    CircularArrayQueue();
    bool isEmpty() const;
    void enqueue(int x);
    void dequeue();
    int peekFront() const;
};

CircularArrayQueue::CircularArrayQueue(): start(0), end(0)
{
}

bool CircularArrayQueue::isEmpty() const
{
    return start == end;
}

void CircularArrayQueue::enqueue(int x)
{
    circularArray[end % CAPACITY] = x;
    end = (end + 1) % CAPACITY;
}

void CircularArrayQueue::dequeue()
{
    start = (start + 1) % CAPACITY;
}

int CircularArrayQueue::peekFront() const
{
    return circularArray[start];
}

TEST_CASE("Test circular array")
{
    CircularArrayQueue a;
    REQUIRE(a.isEmpty());
    REQUIRE_NOTHROW(a.enqueue(1));
    REQUIRE_FALSE(a.isEmpty());
    REQUIRE(a.peekFront() == 1);
    REQUIRE_NOTHROW(a.enqueue(2));
    REQUIRE_NOTHROW(a.enqueue(3));
    REQUIRE_FALSE(a.isEmpty());
    REQUIRE_NOTHROW(a.dequeue());
    REQUIRE(a.peekFront() == 2);
    REQUIRE_NOTHROW(a.dequeue());
    REQUIRE(a.peekFront() == 3);
    REQUIRE_NOTHROW(a.dequeue());
    REQUIRE(a.isEmpty());

    REQUIRE_NOTHROW(a.enqueue(1));
    REQUIRE_NOTHROW(a.enqueue(2));
    REQUIRE_NOTHROW(a.enqueue(3));
    REQUIRE(a.peekFront() == 1);
    REQUIRE_NOTHROW(a.dequeue());
    REQUIRE(a.peekFront() == 2);
    REQUIRE_NOTHROW(a.dequeue());
    REQUIRE(a.peekFront() == 3);
    REQUIRE_NOTHROW(a.dequeue());
    REQUIRE(a.isEmpty());
}
