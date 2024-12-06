#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> vec;

    for (int i = 0; i < count; i++)
    {
        if (i == 0) { vec.emplace_back(step); }
        else 
        {
            vec.emplace_back(vec[i - 1] + step);
        }
    }
    return vec;
}
