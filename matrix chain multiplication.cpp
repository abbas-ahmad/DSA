/*
    Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
    The efficient way is the one that involves the least number of multiplications.
    The dimensions of the matrices are given in an array arr[] of size N (such that N = number of 
    matrices + 1) 
    where the ith matrix has the dimensions (arr[i-1] x arr[i]).

    https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#  

MCM pattern: 

Idea:
- divide the sequence in two parts from i to k  and k+1 to j and calculate the total #multi 
- and add the multiplication of these two parts as arr[i-1] * arr[k] * arr[j]
- do this for all posible division point say k which will lies between 1 to N-1
- store the result for dp

Steps:
1. identify bound for i and j
2. find base case condition
3. find k loop scheme
4. cal ans from temp ans

*/ 

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    int solve(int *arr, int i, int j, vector<vector<int>> &dp){
        //since we need atleast two matrix to multiply we will return if i >= j
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            int temp = solve(arr, i, k, dp) + solve(arr, k+1, j, dp) + arr[i-1] * arr[k] * arr[j];
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N+1, vector<int> (N+1, -1));
        return solve(arr, 1, N-1, dp);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  