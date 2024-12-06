#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int result = 0;

    for (auto x : numbers)
    {
        if (x % 2 == 0)
        {
            result += x;
        }
    }
    return result;
}
