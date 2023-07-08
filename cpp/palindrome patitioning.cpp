/*
    Given a string str, a partitioning of the string is a palindrome partitioning 
    if every sub-string of the partition is a palindrome. 
    Determine the fewest cuts needed for palindrome partitioning of given string.

    https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#

MCM pattern: 

Idea:
- divide the sequence in two parts from i to k  and k+1 to j and find the total #partition required
  and add 1 to it we are partitioning this in this point as well
- do this for all posible division point say k which will lies between 1 to N-1
- store the result for dp

MCM Steps:
1. identify bound for i and j
2. find base case condition
3. find k loop scheme
4. cal ans from temp ans

*/ 
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:

    // Follow MCM Pattern
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j, vector<vector<int>> &dp){
        // if str is "" or single letter no partion required to make it palindrome
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        // already palindrome -> no partition
        if(isPalindrome(s, i, j)){
            dp[i][j] = 0;
            return 0;
        };
        
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            int temp = 1 + solve(s, i, k, dp) + solve(s, k+1, j, dp);
            
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    
    int palindromicPartition(string s){
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
        return solve(s, 0, s.size()-1, dp);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
} 