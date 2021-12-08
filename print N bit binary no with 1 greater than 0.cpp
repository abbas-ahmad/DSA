/*

Given a positive integer n, 
print all n-bit binary numbers having more 1’s than 0’s for any prefix of the number.

- make recursion tree using in-op method
- start with string 1 and answer cannot be started with 0
- add 1 is always a choice for us
- to add 0 we need to check that #0 < #1 
  which make sure that after adding the 0 will atleast make op as #0==#1
- when we reach n == 0, we save the current output 


https://www.youtube.com/watch?v=U81n0UYtk98&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=18
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int n, int zeros, int ones, string  op, vector<string> &ans){
    if(n == 0) {
        ans.push_back(op);
        return;
    }

    string op1 = op;
    op1.push_back('1');
    solve(n - 1, zeros, ones + 1, op1, ans);

    if(zeros < ones){
        string op2 = op;
        op2.push_back('0');
        solve(n - 1, zeros + 1, ones, op2, ans);
    }
}

int main(){
    int n;
    cin >> n;

    vector<string> ans;

    solve(n-1, 0, 1, "1", ans);

    for(string s : ans ){
        cout << s << endl;
    }

    return 0;
}