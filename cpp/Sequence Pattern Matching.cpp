/*
   Given a string str and a pattern find if the patern exist in the str.

    https://www.youtube.com/watch?v=QVntmksK2es&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=31
LCS pattern: 

Idea:
- find the LCS between two string, if the length of lcs is equal to the pattern string then ans is true

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
int LongestRepeatingSubsequence(string str, string pat){
    int m = str.size();
    int n = pat.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    return n == LCS(str, str, m, n, dp);
}