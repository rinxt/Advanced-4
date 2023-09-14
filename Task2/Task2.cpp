#define CATCH_CONFIG_MAIN
#include "../catch_amalgamated.hpp"
#include "list_class.h"

TEST_CASE("PushFront inserts a new element at the beginning of a list", "[List]") {
    List list;
    list.PushFront(1);
    INFO("PushFront doesn't insert a new element at the beginning of a list");
    CHECK(list.Size() == 1);
}

TEST_CASE("PushBack inserts a new element at the end of a list", "[List]") {
    List list;
    list.PushBack(1);
    INFO("PushBack doesn't insert a new element at the end of a list");
    CHECK(list.Size() == 1);
}

TEST_CASE("PopFront deletes element from the start of a list and returns it's value", "[List]") {
    List list;
    INFO("PopFront doesn't throw an exception in case of an empty list");
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    list.PushFront(4);
    INFO("PopFront doesn't return the deleted element's value");
    REQUIRE(list.PopFront() == 4);
    INFO("PopFront doesn't delete element from the start of a list");
    REQUIRE(list.Empty() == true);
}

TEST_CASE("PopBack deletes element from the end of a list and returns it's value", "[List]") {
    List list;
    INFO("PopBack doesn't throw an exception in case of an empty list");
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    list.PushBack(3);
    INFO("PopBack doesn't return the deleted element's value");
    REQUIRE(list.PopBack() == 3);
    INFO("PopBack doesn't delete element from the end of a list");
    REQUIRE(list.Empty() == true);
}


int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}
