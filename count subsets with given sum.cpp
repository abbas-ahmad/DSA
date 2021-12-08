/*
    Given an array arr[] of length N and an integer X, 
    the task is to find the number of subsets with a sum equal to X.

    https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

- Knapsack pattern
- simply modify the subset sum problem which is straightforward

*/

#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>&nums, int n, int sum, vector<vector<int>> &dp){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= sum; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int sum;
    cin >> sum;
    
    vector<vector<int>> dp(n + 1, vector<int>(sum+1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    
    cout << countSubsets(nums, n, sum, dp) << endl;

    return 0;
}