/*
    Given a boolean expression S of length N with following symbols.
    Symbols
        'T' ---> true
        'F' ---> false
    and following operators filled between symbols
    Operators
        &   ---> boolean AND
        |   ---> boolean OR
        ^   ---> boolean XOR
    Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

    https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

MCM pattern: 

Idea:
- divide the sequence in two parts from i to k-1  and k+1 to j and find the total #ways required
- do this for all posible division point say k which will lies between 1 to N-1 
  and k will move from operator to operator i.e. 2 step 
- store the result for dp in 3d array or map

MCM Steps:
1. identify bound for i and j
2. find base case condition
3. find k loop scheme
4. cal ans from temp ans

*/ 

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solve(string s, int i, int j, bool state, unordered_map<string, int> &dp){
        if(i > j) return 0;
        if(i == j){
            if(state) return s[i] == 'T';
            else return s[i] == 'F';
        }
        string key = to_string(i) + ' ' + to_string(j) + ' ' + to_string(state);
        if(dp.find(key) != dp.end()) return dp[key];
        
        int count = 0;
        
        for(int k=i+1;k<j;k+=2){
          
          int lt=solve(s,i,k-1,true,dp);
          int lf=solve(s,i,k-1,false,dp);
          int rt=solve(s,k+1,j,true,dp);
          int rf=solve(s,k+1,j,false,dp);
          
          if(s[k]=='&'){
              if(state==true){
                  count+=lt*rt;
              }
              else{
                  count+=lf*rf+lf*rt+lt*rf;
              }
          }
          
          else if(s[k]=='|'){
              if(state==true){
                  count+=lt*rt+lt*rf+lf*rt;
              }
              else{
                  count+=lf*rf;
              }
          }
          
          else if(s[k]=='^'){
              if(state==true){
                  count += lt * rf + lf * rt;
              }
              else{
                  count += lt * rt + lf * rf;
              }
          }
          
       }
        return dp[key] = count % 1003;
    }
    
    int countWays(int N, string S){
        unordered_map<string, int> dp;
        return solve(S, 0, S.size()-1, true, dp);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  


// using 3d array
class Solution{
public:
int t[201][201][2];
   int solve(string &s, int i, int j,bool state){
       
       if(i>j){
           return 0;
       }
       if(t[i][j][state]!=-1){
           return t[i][j][state];
       }
       if(i==j){
           if(state==true){
               return s[i]=='T';
           }
           else{
               return s[i]=='F';
           }
       }
       
       int count=0;
       for(int k=i+1;k<j;k+=2){
          
          int lt=solve(s,i,k-1,true);
          int lf=solve(s,i,k-1,false);
          int rt=solve(s,k+1,j,true);
          int rf=solve(s,k+1,j,false);
          
          if(s[k]=='&'){
              if(state==true){
                  count+=lt*rt;
              }
              else{
                  count+=lf*rf+lf*rt+lt*rf;
              }
          }
          
          else if(s[k]=='|'){
              if(state==true){
                  count+=lt*rt+lt*rf+lf*rt;
              }
              else{
                  count+=lf*rf;
              }
          }
          
          else if(s[k]=='^'){
              if(state==true){
                  count+=lt*rf+lf*rt;
              }
              else{
                  count+=lt*rt+lf*rf;
              }
          }
          
       }
       
       return  t[i][j][state]=count%1003;
       
   }
    int countWays(int N, string S){
        // code here
         memset(t,-1,sizeof(t));
       return solve(S,0,N-1,true);
    }
};