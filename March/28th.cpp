#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int timer = 1;
    
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, 
             vector<int>& tin, vector<int>& low, vector<int>& mark) {
        
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int children = 0;
        
        for (auto it : adj[node]) {
            if (it == parent) continue; // Skip the edge to the parent
            
            if (!vis[it]) {
                // If the adjacent node is unvisited, it's a child in the DFS tree
                dfs(it, node, adj, vis, tin, low, mark);
                
                // Update the lowest reachable time for the current node
                low[node] = min(low[node], low[it]);
                
                // Check articulation point condition for non-root nodes
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1; // Mark as articulation point
                }
                children++;
            } else {
                // If visited, it's a back-edge. Update the low time.
                low[node] = min(low[node], tin[it]);
            }
        }
        
        // Check articulation point condition for the root node
        if (parent == -1 && children > 1) {
            mark[node] = 1;
        }
    }
    
public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Step 1: Build the Adjacency List
        vector<vector<int>> adj(V);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> vis(V, 0);
        vector<int> tin(V, 0);
        vector<int> low(V, 0);
        
        // Using a hash array (mark) to handle duplicate articulation points
        // Multiple subtrees might flag the same node as an articulation point.
        vector<int> mark(V, 0); 
        
        // Step 2: Traverse the graph (handles disconnected components)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }
        
        // Step 3: Collect and format the results
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        
        if (ans.empty()) {
            return {-1};
        }
        
        return ans;
    }
};