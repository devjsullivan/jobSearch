//
// Created by Kevin Sullivan on 9/8/23.
//
#include "commonObjects.h"
#include <iostream>

thinkObj::thinkObj()
{
    mStringMap.clear();
}
thinkObj::thinkObj(thinkObj &inObj)
{
    for (auto it = inObj.mStringMap.begin(); it != inObj.mStringMap.end(); it++)
    {
        this->mStringMap[it->first] = it->second;
    }
}

void thinkObj::pushNewInt(const int &inIdx, const int &inVal)
{
    if(this->mStringMap.count(inIdx) > 0)
    {
        std::cout << "Sorry, index " << inIdx << " is already in use, and cannot assign value: "
                  << inVal << std::endl;
    }
    else
    {
        this->mStringMap[inIdx] = inVal;
    }
}

void fizzBuzz(const int &inI)
{
    bool isDivByThree = (inI % 3 == 0) ? true : false;
    bool isDivByFive = (inI % 5 == 0) ? true : false;

    if(isDivByThree)
    {
        std::cout << "Fizz";
    }
    if(isDivByFive)
    {
        std::cout << "Buzz";
    }
    if(!isDivByThree && !isDivByFive)
    {
        std::cout << inI;
    }
    std::cout << "\n";
}

