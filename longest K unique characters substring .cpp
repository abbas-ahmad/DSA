/*
    Given a string you need to print the size of the longest possible substring that 
    has exactly K unique characters. 
    If there is no possible substring then print -1.

    https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
 
 Pattern: Sliding window - Variable

 Steps:
 1. Do calculation on current elem
 2. Check condition
 2.1 condi < k
        j++
 2.2 cond > k
        remove ith elem cal until cond satisity
        j++
 2.3 cond == k
        update ans
        j++

*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans = -1;
        unordered_map<int, int> um;
        
        int i = 0, j = 0;
        while(j < s.size()){
            // Step 1. calculation
            if(um.find(s[j]) != um.end()){
                um[s[j]]++;
            }
            else um[s[j]] = 1;
            
            // comparison
            if(um.size() < k){
                j++;
            }
            else if(um.size() > k){
                while(um.size() > k){
                    um[s[i]]--;
                    if(um[s[i]] == 0){
                        um.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
            else{
                ans = max(ans, j-i+1);
                j++;
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends