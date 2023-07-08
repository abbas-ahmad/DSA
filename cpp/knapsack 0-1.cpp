/*
You are given weights and values of N items, put these items in a knapsack of 
capacity W to get the maximum total value in the knapsack. 
Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] 
which represent values and weights associated with N items respectively. 
Also given an integer W which represents knapsack capacity, find out the 
maximum value subset of val[] such that sum of the weights of this
subset is smaller than or equal to W. You cannot break an item, 
either pick the complete item or don’t pick it (0-1 property).

https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

knapsack pattern: 
- we are given array of number and a number representing some max/capacity
- to maximize the given number, we can choose some objects from the array
- 


*/ 


#include<bits/stdc++.h>
using namespace std;

int knapSackHelper(int W, int wt[], int val[], int n, vector<vector<int>> &dp) { 
    if(n == 0 or W == 0) return 0;
    
    if(dp[n-1][W-1] != -1) return dp[n-1][W-1];

    if(W >= wt[n-1]){
        return dp[n-1][W-1] = max(val[n-1] + knapSackHelper(W-wt[n-1], wt, val, n-1, dp), 
                    knapSackHelper(W, wt, val, n-1, dp));
    }
    else{
        return  dp[n-1][W-1] = knapSackHelper(W, wt, val, n-1, dp);
    }
}

int knapSack(int W, int wt[], int val[], int n){
    vector<vector<int>> dp(n, vector<int> (W, -1));
    return knapSackHelper(W, wt, val, n, dp);
}

//bottom up
int knapSack(int W, int wt[], int val[], int n){
    vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
    // return knapSackHelper(W, wt, val, n, dp);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            // check if we have capacity to include current item
            if(j >= wt[i-1]){
                // if we have capacity, we may or may not include it
                // depending on wether we are getting more profit or not 
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);  
            }
            // since we do not have enough capacity, we will not be able to include this item
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}