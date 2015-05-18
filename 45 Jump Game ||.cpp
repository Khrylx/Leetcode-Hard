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

/*int jump(vector<int>& nums)
{
    int N = (int)nums.size();
    if (N == 1) {
        return 0;
    }
    vector<int> jumpNums(N-1,-1);
    
    bool initial = true;
    while (1) {
        for (int i = N-2; i >= 0; i--) {
            if (jumpNums[i] != -1) {
                continue;
            }
            if (initial) {
                if (i + nums[i] >= N-1) {
                    jumpNums[i] = 1;
                }
            }
            else{
                for (int j = max(0,i-nums[i]); j <= i+nums[i]; j++) {
                    if (jumpNums[j] != -1) {
                        if (jumpNums[i] == -1)
                            jumpNums[i] = jumpNums[j]+1;
                        else
                            jumpNums[i] = min(jumpNums[i],jumpNums[j]+1);
                    }
                }
            }
            if (jumpNums[0] != -1) {
                return jumpNums[0];
            }
        }
        initial = false;
    }

}*/

int jump(vector<int>& nums)
{
    int N = (int)nums.size();
    if (N == 1) {
        return 0;
    }
    int cur = 0;
    int next = 0;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        if (i > cur) {
            cur = next;
            count++;
            if (cur >= N-1) {
                return count;
            }
        }
        next = max(next,i+nums[i]);
        
        
    }
    
    return count;
    
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    cout << jump(nums)<<endl;
    return 1;
}

