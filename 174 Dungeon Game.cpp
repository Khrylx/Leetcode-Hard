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
#include <unordered_map>
#include <unordered_set>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon)
{
    if (dungeon.size() == 0 || dungeon[0].size() == 0) {
        return 1;
    }
    
    int N = (int)dungeon.size();
    int M = (int)dungeon[0].size();
    
    dungeon[N-1][M-1] = max(0, -dungeon[N-1][M-1]);
    
    for (int i = N-2 ; i >= 0; i--) {
        dungeon[i][M-1] = max(0,dungeon[i+1][M-1]- dungeon[i][M-1]) ;
    }
    
    for (int i = M-2; i >= 0; i--) {
        dungeon[N-1][i] = max(0,dungeon[N-1][i+1]- dungeon[N-1][i]) ;
    }

    for (int i = N-2; i >= 0; i--) {
        for (int j = M-2; j >= 0; j--) {
            dungeon[i][j] = max(0,min(dungeon[i+1][j],dungeon[i][j+1]) - dungeon[i][j]);
        }
    }
    
    return dungeon[0][0] + 1;
}


int main(){
    int N,M;
    
    cin >> N >> M;
    
    vector<vector<int>> dungeon(N,vector<int>(M));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> dungeon[i][j];
        }
    }
    
    int res = calculateMinimumHP(dungeon);
    
    return 1;
}
