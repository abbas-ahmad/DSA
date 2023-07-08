/*
https://hack.codingblocks.com/app/contests/1499/1506/problem
Ramu has an array of strings. He want to find a string s such that it is a concatenation of sub-sequence of given array and have unique characters.Since,he has just started coding so he needs your help.
A sub-sequence of an array is a set of elements that can be obtained by deleting some elements(posssibly none) from the array and keeping the order same.
Print the maximum possible length of s.

idea:try to append all string for which current string length and candidate string length sum to less than 26 using recusrion
    - for every string we have two choices - either add it in the answer string or skip that string
    - evaluate both the string and return with max length
    - to check unique char string: create 26 length freq array and init it with 0
    - map all the letters at the char -'a' index, if we found any index in the map with 1 i.e it is already seen once and we are seeing it again. so it is duplicate. 
 
*/

#include<bits/stdc++.h>
using namespace std;

int helper(vector<string> &s, int i, string ans){
    if(i == s.size()){
        int map[26] = {0};

        for (int i = 0; i < ans.length(); i++){
            if(map[ans[i]-'a'] == 1)
                return 0;
            else
                map[ans[i]-'a']++;
        }
        return ans.size();
    }
    int op1, op2;
    op1 = op2 = INT_MIN;
    if (s[i].size() + ans.size() <= 26)
    {
        op1 = helper(s, i + 1, ans + s[i]);
    }
    op2 = helper(s, i + 1, ans);

    return max(op1, op2);
}

int uniqueCharString(vector<string>&s){
    string ans;
    return helper(s, 0, ans);
}

int main(){
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    cout << uniqueCharString(v) << endl;

    return 0;
}