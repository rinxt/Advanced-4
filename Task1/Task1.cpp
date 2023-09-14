#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "list_class.h"

TEST_CASE("Empty() returns true for an empty list and false for a non-empty list", "[List]") {
    List list;
    REQUIRE(list.Empty() == true);
    list.PushBack(42);
    REQUIRE(list.Empty() == false);
}

TEST_CASE("Size() returns the correct size for a list", "[List]") {
    List list;
    INFO("Size() doesn't return 0 for an empty list.");
    CHECK(list.Size() == 0);
    SECTION("non-empty list") {
        list.PushBack(1);
        list.PushBack(2);
        list.PushBack(3);
        INFO("List size calculated wrong.");
        REQUIRE(list.Size() == 3);
    }
}

TEST_CASE("Clear() empties the list", "[List]") {
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.Clear();
    INFO("List is not empty after Clear.");
    REQUIRE(list.Empty() == true);
    INFO("List size is not 0 after Clear.");
    REQUIRE(list.Size() == 0);
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}
