/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3. Given word1 = "makes", word2 = "coding", return 1.

https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleEasy/243.html

- apply two pointer
- init both pointer
- update pointer on their respective word
- update the answer  

*/

#include<bits/stdc++.h>
using namespace stdl;

class Solution
{
    int shortestDistance(vector<string> words, string word1, string word2)
    {
        int l = -1, r= -1;
        int shortest =words.length;
        for(int i=0; i< words.length; i++){
            if(words[i] == word1){
                l = i;
            }else if(words[i] == word2){
                r = i;
            }
            if(l >=0 && r >=0){
                shortest = min(shortest, abs(l-r));
            }
        }
        return shortest;
    }
 };