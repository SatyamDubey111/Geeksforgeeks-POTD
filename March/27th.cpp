#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Overload 1: Matches your exact error (Driver passing only 'grid')
    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return calculateMax(n, m, grid);
    }

    // Overload 2: Just in case the driver secretly passes n and m too
    int maxChocolate(int n, int m, vector<vector<int>>& grid) {
        return calculateMax(n, m, grid);
    }
    
    // Overload 3: Standard GeeksforGeeks signature
    int solve(int n, int m, vector<vector<int>>& grid) {
        return calculateMax(n, m, grid);
    }

private:
    // Main DP Logic (Space Optimized to O(M^2))
    int calculateMax(int n, int m, vector<vector<int>>& grid) {
        // Space Optimization: Humein pure 3D array ki zaroorat nahi hai.
        // Sirf agli row (front) aur current row (cur) track karni hai.
        vector<vector<int>> front(m, vector<int>(m, -1e8));
        vector<vector<int>> cur(m, vector<int>(m, -1e8));

        // Base Case: Fill the last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    front[j1][j2] = grid[n - 1][j1];
                else
                    front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // Bottom-up DP
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxChoco = -1e8;
                    
                    // Try all 9 combinations of moves for both robots
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            
                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                int current_val = 0;
                                if (j1 == j2) 
                                    current_val = grid[i][j1] + front[nj1][nj2];
                                else 
                                    current_val = grid[i][j1] + grid[i][j2] + front[nj1][nj2];
                                
                                maxChoco = max(maxChoco, current_val);
                            }
                        }
                    }
                    cur[j1][j2] = maxChoco;
                }
            }
            // Move up: Current row becomes the 'front' row for the next iteration
            front = cur;
        }

        return front[0][m - 1];
    }
};