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
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> solutions;
    priority_queue<pair<int, int>> Q;
    int N = (int)nums.size();
    
    for (int i = 0; i < N; i++) {
        Q.push(make_pair(nums[i], i));
        if (i >= k-1) {
            pair<int, int> P = Q.top();
            while (P.second <= i-k) {
                Q.pop();
                P = Q.top();
            }
            solutions.push_back(P.first);
        }
    }
    
    return solutions;
}

int main(){
    int N;
    cin >> N;
    
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    // [1,3,-1,-3,5,3,6,7]
    vector<int> solutions = maxSlidingWindow(nums, 1);
    
    return 1;
}
