/*
    Given an array A[] of size N and a positive integer K, find the first negative 
    integer for each and every window(contiguous subarray) of size K.

    https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

 Pattern: Sliding window - Fixed

 Steps:
 1. Do calculation on current no
 2. check window size
    2.1 if size is less than k, then increment j
    2.2 if window size is euqal to k, than maintain it
        - calculate ans for this window
        - slide window  


*/

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    queue<long long> q;
    int i = 0, j = 0;
    
    while(j < N){
        if(A[j] < 0) q.push(A[j]);
        
        if(j-i+1 < K) j++;
        else{
            if(q.empty()) ans.push_back(0);
            else ans.push_back(q.front());
            
            if(q.front() == A[i]) q.pop();
            i++;
            j++;
        }
    }
    return ans;
 }