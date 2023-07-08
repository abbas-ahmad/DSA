/*
    Given an array of integers A and an integer B.
    Find the total number of subarrays having bitwise XOR of all elements equals to B.

    https://www.interviewbit.com/problems/subarray-with-given-xor/

    idea:
    An Efficient Solution solves the above problem in O(n) time. 
    Let us call the XOR of all elements in the range [i+1, j] as A, in the range [0, i] as B, 
    and in the range [0, j] as C. If we do XOR of B with C, the overlapping 
    elements in [0, i] from B and C zero out, and we get XOR of all elements in the 
    range [i+1, j], i.e. A. Since A = B XOR C, we have B = A XOR C. Now, if we know the value of C 
    and we take the value of A as m, we get the count of A as the count of all B satisfying this relation. 
    Essentially, we get the count of all subarrays having XOR-sum m for each C. 
    As we take the sum of this count overall C, we get our answer.
    
    Steps:
    

*/

int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    int xr = 0;
    unordered_map<int, int> um;
    for(int x : A){
        xr ^= x;

        if(xr == B) count++;

        if(um.find(xr ^ B) != um.end()){
            count += um[xr ^ B];
        }

        um[xr]++;
    }
    
    return count;
}
