#pragma once
#include <limits>
#include <vector>

int maxOfVector(const std::vector<int>& vec) {
    int result = vec[0];

    for (auto x : vec) 
    {
        if (x > result) {
            result = x;
        }
    }
    return result;
}
