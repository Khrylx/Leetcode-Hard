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

vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> lines;
    
    if ( words.size()==0) {
        return lines;
    }
    
    
    int index = 0;
    
    while (index < words.size()) {
        int widthSum = 0;
        int sIndex = index;
        while (1) {

            int newWidth = (int)words[index].length() + (widthSum==0 ? 0:1);
            if  (widthSum + newWidth > maxWidth)
                break;
            
            widthSum += newWidth;
            index++;
            if (index == words.size()) {
                break;
            }
        }
        
        if (sIndex == index) {
            return lines;
        }
        
        string s;
        int perWhiteSpace = 0;
        int whiteSpaceEx = 0;
        if (index < words.size()){
            if (sIndex + 1 == index) {
                perWhiteSpace = maxWidth-widthSum;
            }
            else{
                perWhiteSpace = (maxWidth-widthSum)/(index - sIndex - 1);
                whiteSpaceEx = (maxWidth-widthSum) % (index - sIndex -1);
            }
        }


        
        for (int i = sIndex; i < index; i++) {
            s += words[i];
            if (sIndex + 1 == index) {
                s += string( perWhiteSpace,' ');
            }
            if (i < index - 1) {
                s += string( perWhiteSpace + (i-sIndex+1 <= whiteSpaceEx ? 2:1),' ');
            }
        }
        if (index == words.size()) {
            s += string(maxWidth - s.length(),' ');
        }
        lines.push_back(s);
    }
    
    return lines;
}


int main(){

    vector<string> words;
    words.push_back("What");
    words.push_back("must");
    words.push_back("be");
    words.push_back("shall");
    words.push_back("be.");
    
    vector<string> lines = fullJustify(words, 12);
    for (int i = 0; i < lines.size(); i++) {
        cout<<lines[i]<<endl;
    }
    return 1;
}

