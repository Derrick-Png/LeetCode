#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> nums = {};
        for(auto i : arr)
        {
            if(nums.find(i) == nums.end())
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] += 1;
            }
            if(nums[i] > arr.size() / 4)
            {
                return i;
            }
        }
        return -1;
    }
};
