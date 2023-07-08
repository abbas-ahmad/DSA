/*
    Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, 
    i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search 
    an element in this array. 
    Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

    https://www.geeksforgeeks.org/search-almost-sorted-array/
 
 Pattern: Binary search

 Steps:
    - we can still apply BS and instead checking only mid now we can check mid, mid-1, mid+1
    - The idea is to compare the key with middle 3 elements, if present then return the index. 
    - If not present, then compare the key with middle element to decide whether to go in left half or right half. 
    - Comparing with middle element is enough as all the elements after mid+2 must be greater 
      than element mid and all elements before mid-2 must be smaller than mid element.
*/


#include <iostream>
using namespace std;

int search(int *arr, int target, int n){
    int left = 0;
    int right = n - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == target)
            return mid;
        else if(mid-1 >= 0 and arr[mid-1] == target)
            return mid - 1;
        else if(mid+1 < n and arr[mid+1] == target)
            return mid + 1;
        if(arr[mid] > target){
            right = mid - 2;
        }
        else
            left = mid + 2;
    }
    return -1;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,target; //
	    cin >> n >> target;
	    int arr[n];
	    for(int i = 0; i < n; i++) cin >> arr[i];
	    
	    cout << search(arr, target, n) << endl;
	}
	return 0;
}