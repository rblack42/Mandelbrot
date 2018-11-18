#include <catch.hpp>
#include "Transform.h"


TEST_CASE("test coordinate translations" ) {
    Transform t1(0,0,1);
    REQUIRE(t1.xc_to_xg(1) == 1);
    REQUIRE(t1.yc_to_yg(1) ==1);
    Transform t2(1,1,1);
    REQUIRE(t2.xc_to_xg(1) == 2);
    REQUIRE(t2.yc_to_yg(1) == 2);
}

TEST_CASE("test coordinate scaling" ) {
    Transform t(0,0,2);
    REQUIRE(t.xc_to_xg(1) == 2);
    REQUIRE(t.yc_to_yg(1) == 2);
}

TEST_CASE("test upper right default coordinates" ) {
    Transform t(300,200,100);
    REQUIRE(t.xc_to_xg(2) == 500);
    REQUIRE(t.yc_to_yg(2) == 400);
}

TEST_CASE("test upper right default reverse coordinates" ) {
    Transform t(300,200,100);
    REQUIRE(t.xg_to_xc(300) == 0);
    REQUIRE(t.yg_to_yc(200) == 0);
}
