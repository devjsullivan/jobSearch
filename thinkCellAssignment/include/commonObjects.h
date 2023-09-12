//
// Created by Kevin Sullivan on 9/8/23.
//

#ifndef HELLOTHINKCELL_COMMONOBJECTS_H
#define HELLOTHINKCELL_COMMONOBJECTS_H

#include <map>
#include <string>

class thinkObj
{
public:
    thinkObj();
    thinkObj(thinkObj &inObj);

    void pushNewInt(const int &inIdx, const int &inVal);

    const std::map<int, int> getMap()
    {
        return mStringMap;
    }
private:
    std::map<int, int> mStringMap;
};

void fizzBuzz(const int &inI);

#endif //HELLOTHINKCELL_COMMONOBJECTS_H
