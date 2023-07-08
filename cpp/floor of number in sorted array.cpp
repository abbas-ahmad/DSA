/*
    Given a sorted array arr[] of size N without duplicates, and given a value x. 
    Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
    Find the index of K(0-based indexing).

    https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
 
 Pattern: Binary search

 Steps:
    - 99% similar to first and last position
    - apply normal BS and keep storing the candidate ans
    - at the end we will have the ans
*/
#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

// Function to find floor of K
// arr[]: integer array of size N
// N: size of arr[]
// K: element whose floor is to find
int findFloor(long long int arr[], int N, long long int K) {
    long long left = 0;
    long long right = N-1;
    long long ans = -1;
    
    while(left <= right){
        long long mid = left + (right - left) / 2;
        
        if(arr[mid] == K) return mid;
        else if(arr[mid] < K){
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return ans;
}

// { Driver Code Starts.

int main() {
	
	long long int t;
	scanf("%lld", &t);
	
	while(t--){
	    int n;
	    scanf("%d", &n);
	    long long int x;
	    scanf("%lld", &x);
	    
	    long long int *arr;
		arr = (long long int *)malloc(n * sizeof(long long int));
	    
	    for(int i = 0;i<n;i++){
	        scanf("%lld", &arr[i]);
	    }
	    printf("%d\n", findFloor(arr, n, x) );
	   
	}
	
	return 0;
}

  // } Driver Code Ends