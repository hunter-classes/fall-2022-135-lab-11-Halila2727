#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "profile.h"
#include "network.h"
#include "doctest.h"

TEST_CASE("Getting User and Display Name")
{
    Profile prof1("Halila2727", "Halil");
    Profile prof2("yankeesRF", "Aaron Judge");
    Profile prof3;
    CHECK(prof1.getUsername() == "Halila2727");
    CHECK(prof2.getUsername() == "yankeesRF");
    CHECK(prof3.getUsername() == "");
    CHECK(prof1.getFullName() == "Halil (@Halila2727)");
    CHECK(prof2.getFullName() == "Aaron Judge (@yankeesRF)");
    CHECK(prof3.getFullName() == " (@)");
}

TEST_CASE("Adding User to Network")
{
    Network nw1;
    CHECK(nw1.addUser("Halila2727", "Halil") == 1);
    CHECK(nw1.addUser("TEwithButterFingers", "Evan Engram") == 1);
    CHECK(nw1.addUser("!!!!", "Exclaim") == 0);
    CHECK(nw1.addUser("Saquon!", "Saquon") == 0);
    CHECK(nw1.addUser("Daniel Jones", "Daniel Jones") == 0);
}

TEST_CASE("Users Following Other Users"){
    Network nw1;
    nw1.addUser("Halila2727", "Halil");
    nw1.addUser("saquon", "Saquon Barkley");
    nw1.addUser("DJQB", "Daniel Jones");
    nw1.addUser("yankeesRF", "Aaron Judge");

    CHECK(nw1.follow("Halila2727", "saquon") == true);
    CHECK(nw1.follow("Halila2727", "saquon!") == false);
    CHECK(nw1.follow("Halila2727", "DJQB") == true);
    CHECK(nw1.follow("DJQB", "saquon") == true);
    CHECK(nw1.follow("yankeesRF", "saquon") == true);
    CHECK(nw1.follow("TEone", "saquon") == false);
    CHECK(nw1.follow("saquon", "DJQB") == true);
    CHECK(nw1.follow("saquon", "TEone") == false);
}