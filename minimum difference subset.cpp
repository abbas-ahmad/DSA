/*
    Given a set of integers, 
    the task is to divide it into two sets S1 and S2 such that the absolute difference between 
    their sums is minimum. 
    If there is a set S with n elements, then if we assume Subset1 has m elements, 
    Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

    https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

- Knapsack pattern
- simply modify the subset sum problem which is straightforward

idea:
- we want two subsets s1 and s2 s.t. abs(s2-s1) ==> minimum
- let arr sum is S then if s2 = S-s1 , which means we want to minimize S-2s1
- Now we need to find the subset s1
- this subset can range between {} to {whole array} i.e. [0-S]
- so we can assume s1 to be in [0-S/2] range to minimize the difference
- now we want the subset s1 between [0-S/2] which minimize the S-2s1
- we can try subset sum for s1 from sum= 0 to S/2 but since there may be sum which cannot
  be formed with the array array elements 
- so we need to ignore these sum
- to find all the candidate subarray between 0-S/2 we can use subset sum dp table's last row

*/

#include<bits/stdc++.h>
using namespace std;

void subsetSum(vector<int>&nums, int sum, int n, vector<vector<bool>>&dp){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= sum; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i][j - nums[i - 1]] or dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}

int findMinimumDiffSubset(vector<int> & nums){
    int sum = 0;
    for(int x : nums) sum += x;

    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= dp.size(); i++)
        dp[i][0] = true;
    cout << "dsd";
    subsetSum(nums, sum, nums.size(), dp); // to get the last row of dp table
    
    int minDiff = INT_MAX;
    for (int i = 0; i < sum / 2; i++){
        if(dp[nums.size()][i] == true)
            minDiff = min(minDiff, sum - 2 * nums[i]);
    }
    return minDiff;
}

int main(){

     int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << findMinimumDiffSubset(nums) << endl;

    return 0;
}