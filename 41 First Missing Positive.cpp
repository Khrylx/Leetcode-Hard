//
//  main.cpp
//  Leetcode
//
//  Created by Eric on 15/5/14.
//  Copyright (c) 2015年 Eric. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void swap(int& a ,int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int firstMissingPositive(vector<int>& nums)
{
    int N = (int)nums.size();
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i]-1!=i && nums[i]!=nums[nums[i]-1] && nums[i]>0 && nums[i] <= N) {
            swap(nums[i], nums[nums[i]-1]);
        }
    }
    
    for (int i = 0 ; i < nums.size(); i++) {
        if (nums[i] != i+1) {
            return i+1;
        }
    }
    
    return N+1;
}

int main()
{
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    cout << firstMissingPositive(nums) <<endl;
    return 1;
}

