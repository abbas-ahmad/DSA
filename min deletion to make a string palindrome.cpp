/*
   Given a string of S as input. Your task is to write a program to remove or delete
   the minimum number of characters from the string so that the resultant string is a palindrome.
   Note: The order of characters in the string should be maintained

   https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1

LCS pattern: 

Idea:
- we ca see that to get the min number of deletion, we need to convert the given string in longest palind subseq
- so #deletion = S.size() - len(LPS)

*/ 
#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int m, int n, vector<vector<int>> &dp){
    if(m == 0 or n == 0) return 0;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}

int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    
    int m = s.size();
    
    vector<vector<int>> dp(m+1, vector<int> (m+1, 0));
    return LCS(s, t, m, m, dp);
}
int minimumNumberOfDeletions(string S) { 
    int lps = longestPalindromeSubseq(S);
    
    return S.size() - lps;
} 