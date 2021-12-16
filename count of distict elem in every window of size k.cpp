/*
    You are given an array of N integers, A1, A2 ,..., AN and an integer B. 
    Return the of count of distinct numbers in all windows of size B.
    Formally, return an array of size N-B+1 where i'th element in this array contains number of 
    distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.
    NOTE:  if B > N, return an empty array.
    Link:https://www.interviewbit.com/problems/distinct-numbers-in-window/

    Approach: Sliding window fixed size
    - keep a freq map of all char in the window of size k
    - size of this map will be ans for that specific window
    - to slide window, remove/decrease freq count of ith elment from map
    - if freq become 0, remove it from map
*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    unordered_map<int, int> um; // no -> count
    int n = A.size();
    if(n < B) return ans;

    int j = 0, i = 0;
    while(j < n){
        um[A[j]]++;

        if(j - i + 1 < B){
            j++;
            continue;
        }
        else{
            ans.push_back(um.size());

            um[A[i]]--;
            if(um[A[i]] == 0) um.erase(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}