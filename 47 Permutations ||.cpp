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
#include <stack>
#include <unordered_set>

using namespace std;

void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& solutions)
{
    if (start == nums.size()-1) {
        solutions.push_back(nums);
    }
    
    unordered_set<int> Set;
    
    for (int i = start; i < nums.size(); i++) {
        if (Set.find(nums[i])!=Set.end()) {
            continue;
        }
        
        Set.insert(nums[i]);
        swap(nums[i], nums[start]);
        permuteHelper(nums, start+1, solutions);
        swap(nums[i], nums[start]);
        
    }
    
}


vector<vector<int>> permuteUnique(vector<int>& nums)
{
    vector<vector<int>> solutions;
    
    permuteHelper(nums, 0, solutions);
    
    return solutions;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
//    nums.push_back(1);
//    nums.push_back(4);
    vector<vector<int>> solutions = permuteUnique(nums);
    return 1;
}

