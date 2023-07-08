/*
    Given arrival and departure times of all trains that reach a railway station. 
    Find the minimum number of platforms required for the railway station so that no train is kept waiting.
    Consider that all the trains arrive on the same day and leave on the same day. 
    Arrival and departure time can never be the same for a train but we can have arrival time of one train equal 
    to departure time of the other. At any given instance of time, same platform can not be used for both departure 
    of a train and arrival of another train. In such cases, we need different platforms.

    https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

    idea:
    - we can sort the trains based on arrival time
    - we put the first trains(end time only) in heap
    - when next come we check if the train in heap is left or not
    - if left, we can use its platform otherwise we need another platform
    - the number of trains inside heap are the trains which need platform simultaneously
    - so at any time the max size of heap gives us no of platform
*/

// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    1.methods
    T:O(nlogn) S:O(n)
    int findPlatform(int arr[], int dep[], int n){
        vector<pair<int, int>> trains(n);
        
        for(int i = 0; i < n; i++){
            trains[i].first = arr[i];
            trains[i].second = dep[i];
        }
        
        sort(trains.begin(), trains.end());
        priority_queue<int, vector<int>, greater<int>> heap;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(heap.size() > 0 and heap.top() < trains[i].first){
                heap.pop();
            }
            heap.push(trains[i].second);
            ans = max(ans, (int)heap.size());
        }
        return ans;
    }

    //Method 2 : T;O(nlogn) S:O(1)
    int findPlatform(int arr[], int dep[], int n)
    {
        int trains = 0;
    	int platforms = 0;
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int j = 0;
    	int i = 0;
    	
    	while(i < n and j < n){
    	    if(dep[j] < arr[i]){
    	        trains--;
    	        j++;
    	    }
    	    else{
    	        trains++;
    	        i++;
    	    }
    	    platforms = max(platforms, trains);
    	}
    	return platforms;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends