/*
    Author: Halil Akca
    Course: CSCI-135
    Instructor: Zamansky
    Assignment: Lab 11 Task B
    This is the cpp file for profile class
*/

#include <iostream>
#include <string>
#include "network.h"

int Network::findID(std::string usrn)
{
    for(int i=0; i<MAX_USERS; i++)
    {
        if(usrn == profiles[i].getUsername())
        {
            return i;
        }
    }
    return -1;
}

Network::Network()
{
    numUsers = 0;
}

bool Network::addUser(std::string usrn, std::string dspn)
{
    if(usrn == "")
    {
        return false;
    }
    
    for (int i = 0; i < usrn.length(); i++)
    {
        if (isdigit(usrn[i])==false && isalpha(usrn[i])==false)
        {
            return false;
        }
    }

    if(findID(usrn) != -1)
    {
        return false;
    }

    if(numUsers == MAX_USERS)
    {
        return false;
    }

    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;
}