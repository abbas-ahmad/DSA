/* 

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.
Where:
A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.

idea: 
-We need to sort the intervals by start time in order to make things easier. 
-A very straightforward way is to have a List of Interval and stored as the occupied interval of a room. 
-And the size of the List will be the number of rooms required.
-Because the start time is in increasing order, so that when you found a meeting 
that needs to be put into one room, it doesn't matter which available room to put in. 
E.g. if there are three rooms can support a meeting at 1pm and the end time of three rooms are 
9 am , 10 am and 11 am. We can arrange this meeting at 1pm to any of the three. 
Because we know the next (if has next) meeting will start later than 1pm. 
No matter where we put 1pm meeting, we will have only two rooms available for the later ones.
-Because we only care about the end time of a room, so actually we can use a min-heap 
to keep track of end time so that we don't need to iterate over the list of rooms. 
Because for a heap. add takes O(logn) in worse case and peek takes O(1) which would be mush faster.

https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/253-meeting-rooms-ii---medium.html
*/

#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int> > &A) {
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(A.begin(), A.end());

    for(int i = 0; i < A.size(); i++){
        if(pq.empty()){
            pq.push(A[i][1]);
            continue;
        }

        if(pq.top() <= A[i][0]){
            pq.pop();
        }

        pq.push(A[i][1]);
    }

    return pq.size();
}