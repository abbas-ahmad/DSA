/*
    Count the pair of subsets S1 and S2 such that S1-S2 = Diff 
    https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12

- Knapsack pattern
- simply modify the subset sum problem which is straightforward

idea:
- we want two subset st s1-s2 = diff  eqn 1
- we already know that  s1+s2 = S     eqn 2
- adding 1 and 2 we get 2s1 = diff + S ==> s1 = (diff + S) / 2
- which means this problem is reduced to count subset with sum equal to (diff+S)/2
*/

#include<bits/stdc++.h>
using namespace std;

int countSubsetWithGivenSum(vector<int>&nums, int sum){
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i < dp.size(); i++)
        dp[i][0] = 1;

    for (int i = 1; i < dp.size(); i++){
        for (int j = 1; j <= sum; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i - 1][j-nums[i-1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[nums.size()][sum];
}

int countSubsetWithGivenDiff(vector<int> &nums, int diff){
    int sum = 0;
    for (int x: nums)
        sum += x;

    if((sum + diff) % 2 != 0)
        return 0;
    return countSubsetWithGivenSum(nums, (sum + diff) / 2);
}

int main(){

    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int diff;
    cin >> diff;
    cout << countSubsetWithGivenDiff(nums, diff) << endl;

    return 0;
}