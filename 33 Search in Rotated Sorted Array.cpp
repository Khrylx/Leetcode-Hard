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

using namespace std;



int search(vector<int>& nums, int target)
{
    
    if (nums[0] == target) {
        return 0;
    }
    if (nums.back() == target) {
        return (int)nums.size()-1;
    }
    
    int left = 0;
    int right = (int)nums.size()-1;
    
    while (right - left > 1) {
        //bool sorted = nums[left] < nums[right];
        
        int newPos = (left + right)/2;
        if (nums[newPos] == target) {
            return newPos;
        }
        else if(nums[newPos] > target){
            if (nums[newPos] > nums[left] && nums[left] > target) {
                left = newPos;
            }
            else{
                right = newPos;
            }
        }
        else{
            if (nums[newPos] < nums[left] && nums[left] < target) {
                right = newPos;
            }
            else{
                left = newPos;
            }
        }

    }
    
    return -1;
};

int main()
{
    int N,K;
    cin >> N >> K;
    
    vector<int> nums(N);
    for (int i = 0 ; i < N; i++) {
        cin >> nums[i];
    }

    cout<<"solution:"<<search(nums,K);
    
    return 1;
}

