/*
FOLLOW KNAPSACK PATTERN
Given an array of non-negative integers, and a value sum, 
determine if there is a subset of the given set with sum equal to given sum. 

https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=4&query=category[]Dynamic%20Programmingpage4category[]Dynamic%20Programming
knapsack pattern: 
- we are given array of number and a number representing some max/capacity
- to maximize the given number, we can choose some objects from the array

*/ 


#include<bits/stdc++.h>
using namespace std;


bool isSubsetSum(int n, int arr[], int W){
    vector<vector<bool>> dp(n+1, vector<bool> (W+1, false));
    for(int i = 0; i <=n; i++){
        dp[i][0] = true;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            // check if we have capacity to include current item
            if(j >= arr[i-1]){
                // if we have capacity, we may or may not include it
                // depending on wether we are getting more profit or not 
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];  
            }
            // since we do not have enough capacity, we will not be able to include this item
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}