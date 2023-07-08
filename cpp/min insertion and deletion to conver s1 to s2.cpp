/*
   Given two strings str1 and str2. The task is to remove or insert the minimum number of 
   characters from/in str1 so as to transform it into str2. It could be possible that the 
   same character needs to be removed/deleted from  one point of str1 and inserted to 
   some another point.

   https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

LCS pattern: 

Idea:
- we can observe that in order to conver s1 to s2, we are not touch certains letters, 
- these letters form the LCS of s1 and s2
- so to convert s1 to s2 we first convert the s1 to LCS and then LCS to s2
- so total deletion = len(s1) - len(LCS)
- total insertion = len(s2) - len(LCS) 

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

int minOperations(string str1, string str2) { 
    int m = str1.size();
    int n = str2.size();
    
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    
    int lcs = LCS(str1, str2, m, n, dp);
    
    int ans = m - lcs;
    ans += (n - lcs);
    return ans;
}