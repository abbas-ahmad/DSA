/*
   Given a string str, find the length of the longest repeating subsequence 
   such that it can be found twice in the given string. 
   The two identified subsequences A and B can use the same ith character from string str 
   if and only if that ith character has different indices in A and B.

    https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
LCS pattern: 

Idea:
- we want to find the common subseq in the given str only
- so we can modify the LCS st it does not match the char with same index
- in this way we will find the common subseq which will we repeating but at the diff index

*/ 
#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int m, int n, vector<vector<int>> &dp){
    if(m == 0 or n == 0) return 0;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i-1] == s2[j-1] and i != j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}
int LongestRepeatingSubsequence(string str){
    int m = str.size();
    vector<vector<int>> dp(m+1, vector<int> (m+1, 0));
    return LCS(str, str, m, m, dp);
}