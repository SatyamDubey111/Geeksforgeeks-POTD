class Solution {
public:
    // Change the name from orangesRotting to orangesRot
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        int freshCount = 0;
        
        // Initial setup
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (mat[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        // ... (the rest of the logic remains exactly the same)
        
        int timeNeeded = 0;
        int rottedByUs = 0;
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            timeNeeded = max(timeNeeded, t);
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + dRow[i];
                int ncol = c + dCol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1) {
                    mat[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                    rottedByUs++;
                }
            }
        }
        
        return (rottedByUs == freshCount) ? timeNeeded : -1;
    }
};