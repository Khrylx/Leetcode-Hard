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

bool myCompare(Interval& interval1, Interval& interval2){
    return interval1.start < interval2.start;
}

vector<Interval> merge(vector<Interval>& intervals)
{
    vector<Interval> solutions;
    
    if (intervals.empty()) {
        return solutions;
    }
    sort(intervals.begin(), intervals.end(), myCompare);
    
    int lastStart = intervals[0].start;
    int lastEnd = intervals[0].end;
    
    for (int i = 1; i < intervals.size(); i++) {
        Interval& inter = intervals[i];
        
        if (inter.start > lastEnd) {
            solutions.push_back(Interval(lastStart, lastEnd));
            lastStart = inter.start;
            lastEnd = inter.end;
        }
        else if (inter.end > lastEnd){
            lastEnd = inter.end;
        }
    }
    
    solutions.push_back(Interval(lastStart, lastEnd));
    
    return solutions;
    
    
}

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));
    
    
    intervals = merge(intervals);
    
    return 1;
}

