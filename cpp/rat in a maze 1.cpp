/*
    Given weights and values of N items, we need to put these items in a knapsack of capacity W to
    get the maximum total value in the knapsack.
    Note: Unlike 0/1 knapsack, you are allowed to break the item. 

*/
idea: Backtrack pattern
// T: 4^(n*n) - at each cell we have 4 choice
// S: O(n+n) - longest path
// short version
void solve(int row, int col, vector<vector<int>>& maze, vector<vector<bool>>& visited, string path, vector<string>& ans, int n){
        if(row == n-1 and col == n-1){
            ans.push_back(path);
            return;
        }
        
        string moves = "DLRU";// D      L        R         U
        vector<vector<int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        
        for(int i = 0; i < 4; i++){
            vector<int> d = dirs[i];
            int r = row + d[0];
            int c = col + d[1];
            
            if(r < n and c < n and r >= 0 and c >= 0 and !visited[r][c] and maze[r][c] == 1){
                visited[row][col] = true;
                solve(r, c, maze, visited, path + moves[i], ans, n);
                visited[row][col] = false;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        vector<string> ans;
        if(m[0][0] == 1) solve(0, 0, m, visited, "", ans, n);
        return ans;
    }

class Solution{
    public:
    void solve(int row, int col, vector<vector<int>>& maze, vector<vector<bool>>& visited, string path, vector<string>& ans, int n){
        if(row == n-1 and col == n-1){
            ans.push_back(path);
            return;
        }    
        //down
        if(row+1 < n and !visited[row+1][col] and maze[row+1][col] == 1){
            visited[row][col] = true;
            solve(row+1, col, maze, visited, path + "D", ans, n);
            visited[row][col] = false;
        }
        //left
        if(col-1 >= 0 and !visited[row][col-1] and maze[row][col-1] == 1){
            visited[row][col] = true;
            solve(row, col-1, maze, visited, path + "L", ans, n);
            visited[row][col] = false;
        }
        //right
        if(col+1 < n and !visited[row][col+1] and maze[row][col+1] == 1){
            visited[row][col] = true;
            solve(row, col+1, maze, visited, path + "R", ans, n);
            visited[row][col] = false;
        }
        //up
        if(row-1 >= 0 and !visited[row-1][col] and maze[row-1][col] == 1){
            visited[row][col] = true;
            solve(row-1, col, maze, visited, path + "U", ans, n);
            visited[row][col] = false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        vector<string> ans;
        if(m[0][0] == 1) solve(0, 0, m, visited, "", ans, n);
        return ans;
    }