/*
link:https://titanwolf.org/Network/Articles/Article?AID=c4b3bbc1-db75-4704-bc5f-dea29fba20d6#gsc.tab=0

*/

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> g;

        for (int i = 0; i < pid.size(); i++){
            g[ppid[i]].push_back(pid[i]);
        }

        vector<int> ans;
        queue<int> q;
        q.push(kill);

        while(!q.empty()){
            int p = q.front();
            q.pop();

            ans.push_back(p);
            for(auto child : g[p]){
                q.push(child);
            }
        }
        return ans;
    }
};