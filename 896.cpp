#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isI = false;
        bool isD = false;
        if(nums.size() == 1)
        {
            return true;
        }
        else
        {
            for(int i = 1; i < nums.size(); i++)
            {
                if(isI || isD)
                {
                    if(isI && nums[i] < nums[i - 1])
                    {
                        return false;
                    }
                    else if(isD && nums[i] > nums[i - 1])
                    {
                        return false;
                    }
                }
                else if(nums[i] != nums[i - 1])
                {
                    isI = nums[i] > nums[i - 1];
                    isD = nums[i] < nums[i - 1];
                }
            }
            return true;
        }
    }
};
