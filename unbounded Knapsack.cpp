/*
    Given a knapsack weight W and a set of n items with certain value vali and weight wti, 
    we need to calculate the maximum amount that could make up this quantity exactly. 
    This is different from classical Knapsack problem, 
    here we are allowed to use unlimited number of instances of an item..

    Same problem:
    Given a rod of length n inches and an array of prices that includes prices of all pieces 
    of size smaller than n. Determine the maximum value obtainable by cutting up the rod and 
    selling the pieces. For example, if the length of the rod is 8 and the values of different 
    pieces are given as the following, 
    then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)
    https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

    https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

knapsack pattern: 
- we are given array of number and a number representing some max/capacity
- to maximize the given number, we can choose some objects from the array

Idea:
- only diff in this case is that in unbounded KS if we select an element we still 
  have that element to add further since we have inf supply of items

*/ 


#include<bits/stdc++.h>
using namespace std;

int unbounded_knapsack(vector<int> & wt, vector<int> & val, int n, int W){
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= W; j++){
            if(wt[i-1] <= j){
                //  in unbounded KS if we select an element we still have that element to add further 
                // since we have inf supply of items
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main(){

    int n;
    cin >> n;

    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int W;
    cin >> W;

    cout << unbounded_knapsack(wt, val, n, W) << endl;
    return 0;
}