/*
    Given an array of n elements, where each element is at most k away from its target position. 
    The task is to print array in sorted form.

    https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0#
 
 Pattern: Heap
    - sorting is always an option

 Steps:
    - we can put the first k element in the minheap then the min element will be on top
    - we can delete the min/top element and put new element in the heap to make it of size k
    - again we can find the 2nd min elment and so on, we can sort the whole array like this in nlogk time  
*/


#include <iostream>
#include<queue>
using namespace std;

void merge(int *arr, int k, int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
        
        if(pq.size() == k){
            cout << pq.top() << " ";
            pq.pop();
        }
    }
    
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    int arr[n];
	    for(int i = 0; i < n; i++) cin >> arr[i];
	    
	    merge(arr, k, n);
	    cout << endl;
	}
	return 0;
}