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

using namespace std;

int trap(vector<int>& height)
{
    stack<int> S;
    int res = 0;
    for (int i = 0; i < (int)height.size(); i++) {
        if (height[i] == 0) {
            continue;
        }
        int threshold = 0;
        while (!S.empty() && height[S.top()] < height[i]) {
            res += (height[S.top()]-threshold)*(i-S.top()-1);
            threshold = height[S.top()];
            S.pop();
        }
        if (!S.empty()) {
            res += (height[i]-threshold)*(i-S.top()-1);
        }
        S.push(i);

    }
    
    return res;
}

int main()
{
    vector<int> height;
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);
    cout << trap(height) <<endl;
    return 1;
}

