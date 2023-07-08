/* 

Given an array of meeting time intervals consisting of start and end times[[s1,e1],[s2,e2],...] 
(si< ei), determine if a person could attend all meetings.

idea: The idea here is to sort the meetings by starting time. 
Then, go through the meetings one by one and make sure that each meeting ends before the next one starts.

 https://aaronice.gitbook.io/lintcode/sweep-line/meeting-rooms
*/

#include<bits/stdc++.h>
using namespace std;

bool isOverlap(vector<int> i1, vector<int> i2){
    if(i1[2] < i2[0])
        return false;
    return true;
}

bool canAttendAllMeetings(vector<vector<int>>& intervals){
    if(intervals.size() <= 1) return true;
    sort(intervals.begin(), intervals.end());

    for (int i = 1; i < intervals.size(); i++){
        if(isOverlap(intervals[i-1], intervals[i])){
            return false;
        }
    }
    return true;
}