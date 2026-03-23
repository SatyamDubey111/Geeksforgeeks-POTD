#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);
        vector<int> indegree(V, 0);

        // Step 1: Graph construction & In-degree calculation
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u] = v;
            indegree[v]++;
        }

        queue<int> q;
        vector<bool> vis(V, false);

        // Step 2: Queue mein In-degree 0 wale nodes dalo
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Kahn's Algorithm se non-cycle nodes ko "peel off" karo
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = true; // Mark as visited (removed from graph)

            int neighbor = adj[node];
            if (neighbor != -1) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Jo nodes bach gaye, wo cycle hain. Unki length nikalo!
        int max_cycle = -1;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                int curr = i;
                int length = 0;
                
                // Traverse the cycle
                while (!vis[curr]) {
                    vis[curr] = true; // Mark nodes of this cycle as visited
                    curr = adj[curr];
                    length++;
                }
                max_cycle = max(max_cycle, length);
            }
        }

        return max_cycle;
    }
};