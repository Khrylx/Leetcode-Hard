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

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
{
    vector<pair<int, int>> solutions;
    list<pair<int, int>> tmpSol;
    int N = (int)buildings.size();
    if (N == 0) {
        return solutions;
    }
    
    tmpSol.push_back(pair<int, int>(buildings[0][0],buildings[0][2]));
    tmpSol.push_back(pair<int, int>(buildings[0][1],0));
    
    for (int i = 1; i < N; i++) {
        vector<pair<int, int>> newSol;
        int Li = buildings[i][0];
        int Ri = buildings[i][1];
        int Hi = buildings[i][2];
        int M = (int)tmpSol.size();

        int prevH;
        while ( !tmpSol.empty() && tmpSol.front().first < Li) {
            if (solutions.empty() || solutions.back().second != tmpSol.front().second) {
                solutions.push_back(tmpSol.front());
            }
            prevH = tmpSol.front().second;
            tmpSol.pop_front();
        }
        list<pair<int, int>>::iterator itr = tmpSol.begin();
        if ( tmpSol.empty() || tmpSol.front().first > Li) {
            tmpSol.push_front(pair<int, int>(Li,max(prevH,Hi)));
        }

        while (itr != tmpSol.end() && itr->first < Ri) {
            prevH = itr->second;
            itr->second = max(Hi,itr->second);
            itr++;
        }
        if ( itr == tmpSol.end() || itr->first > Ri) {
            tmpSol.insert(itr, pair<int,int>(Ri,prevH));
        }
    }
    
    for (list<pair<int, int>>::iterator itr = tmpSol.begin(); itr != tmpSol.end(); itr++) {
        if (solutions.empty() || solutions.back().second != itr->second) {
            solutions.push_back(*itr);
        }
    }
    
    return solutions;
}

int main()
{
//    int N;
//    cin >> N;
//    vector<int> nums(N);
//    
//    for (int i = 0; i < N; i++) {
//        cin >> nums[i];
//    }
//    [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8]
    vector<vector<int>> buildings;
    vector<int> sol(3);
    sol[0] = 0;
    sol[1] = 2;
    sol[2] = 3;
    buildings.push_back(sol);
    sol[0] = 2;
    sol[1] = 5;
    sol[2] = 3;
    buildings.push_back(sol);
//    sol[0] = 5;
//    sol[1] = 12;
//    sol[2] = 12;
//    buildings.push_back(sol);
//    sol[0] = 15;
//    sol[1] = 20;
//    sol[2] = 10;
//    buildings.push_back(sol);
//    sol[0] = 19;
//    sol[1] = 24;
//    sol[2] = 8;
//    buildings.push_back(sol);
    
    
    vector<pair<int, int>> solutions = getSkyline(buildings);
    return 1;
}
