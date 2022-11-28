/*
    Author: Halil Akca
    Course: CSCI-135
    Instructor: Zamansky
    Assignment: Lab 11 Task A
    This is the cpp file for profile class
*/

#include <iostream>
#include <string>
#include "profile.h"

Profile::Profile()
{
    username = "";
    displayname = "";
}

Profile::Profile(std::string usrn, std::string dspn)
{
    username = usrn;
    displayname = dspn;
}
//Profile::Profile(std::string usrn, std::string dspn) : username(usrn), displayname(dspn) { }

std::string Profile::getUsername()
{
    return username;
}

std::string Profile::getFullName()
{
    return (displayname + " (@" + username + ")");
}

void Profile::setDisplayName(std::string dspn)
{
    displayname = dspn;
}