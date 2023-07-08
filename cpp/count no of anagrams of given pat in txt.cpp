/*
    Given a word pat and a text txt. 
    Return the count of the occurences of anagrams of the word in the text.

    https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1#
 
 Pattern: Sliding window - Fixed

 Steps:
 1. Do calculation on current no
 2. check window size
    2.1 if size is less than k, then increment j
    2.2 if window size is euqal to k, than maintain it
        - calculate ans for this window
        - slide window  


*/


public:
	int search(string pat, string txt) {
	    int ans = 0;
	    unordered_map<char, int> um;
	    int i = 0, j = 0;
	    
	    //make freq map of pat
	    for(char c : pat){
	        if(um.find(c) != um.end()){
	            um[c]++;
	        }
	        else um[c] = 1;
	    }
	    // keep track of total distinct unmatched chars
	    int count = um.size();
	    while(j < txt.size()){
	        // check if cur exit in map if exits decrement its freq
	        if(um.find(txt[j]) != um.end()){
	            um[txt[j]]--;
	            
	            // if freq become zero decrement count/unmatched chars
	            // since we fully matched a char
	            if(um[txt[j]] == 0) count--;
	        }
	        
	        //check if we reach valid window size
	        if(j-i+1 < pat.size()){
	            j++;
	        }
	        // if we have valid window size
	        // check if cur window is anagram
	        // and slide the window
	        else{
	            // if cur window is anagram, then total distict unmatched chars (count) 
	            // must be zero
	            if(count == 0) ans++;
	            
	            // slide window
	            // update freq map for ith char, which will be out of the window
    	        if(um.find(txt[i]) != um.end()){
    	            um[txt[i]]++;
    	            
    	            // if freq of ith char becomes 1 it means we have one more char to be matched
    	            // so increment unmatched char count
    	            if(um[txt[i]] == 1) count++;
    	        }
	            
	            i++;j++;
	        }
	    }
	    return ans;
	}

};
