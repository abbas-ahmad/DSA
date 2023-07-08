/*
    What is the maximum number of meetings that can be accommodated in the meeting room 
    when only one meeting can be held in the meeting room at a particular time?

    Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

    https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

    idea:
    - sort the meetings by their end time
    - start with first meeting, note down the end time of started meeting 
    - to check for next meeting we need to have start time of next meeting greater than the started meetings's end time    
    
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{    
    private:
        struct meeting{
            int start;
            int end;
        };
        static bool comp(meeting m1, meeting m2){
            return m1.end < m2.end;
        }
    public:
    //Function to find the maximum number of meetings that can
    //be performed i n a meeting room.
    
    int maxMeetings(int start[], int end[], int n){
        vector<meeting> meets(n);
        for(int i = 0; i < n; i++){
            meets[i].start = start[i];
            meets[i].end = end[i];
        }
        sort(meets.begin(), meets.end(), comp);
        
        int ans = 1;
        int lastEnd = meets[0].end;
        for(int i = 1; i < n; i++){
            if(meets[i].start > lastEnd){
                ans++;
                lastEnd = meets[i].end;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends