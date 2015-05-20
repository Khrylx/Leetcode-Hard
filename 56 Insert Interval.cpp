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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    vector<Interval> newIntervals;
    
    bool newIntInserted = false;
    for (int i = 0; i < intervals.size(); i++) {
        Interval& inter = intervals[i];
        if (inter.end < newInterval.start ) {
            newIntervals.push_back(inter);
        }
        else if(inter.start > newInterval.end){
            if (!newIntInserted) {
                newIntervals.push_back(newInterval);
                newIntInserted = true;
            }
            
            newIntervals.push_back(inter);

        }
        else{
            newInterval.start = min(newInterval.start , inter.start);
            newInterval.end = max (newInterval.end , inter.end);
        }
    }
    
    if (!newIntInserted) {
        newIntervals.push_back(newInterval);
    }
    return newIntervals;
}


int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,2));
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(12,16));
    
    
    intervals = insert(intervals, Interval(4,9));
    
    return 1;
}

