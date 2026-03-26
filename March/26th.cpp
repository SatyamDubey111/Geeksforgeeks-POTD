
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        
        // Adjacency list: {neighbor, time}
        vector<pair<int, int>> adj[n];
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        // dist[i] stores min time, ways[i] stores number of ways
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        // Min-heap: {time, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Agar current distance already stored distance se zyada hai, toh skip karein
            if (d > dist[u]) continue;

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int time = neighbor.second;

                // Case 1: Chota rasta mila
                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    ways[v] = ways[u]; // Purane ways discard, naye ways copy
                    pq.push({dist[v], v});
                }
                // Case 2: Same length ka ek aur rasta mila
                else if (dist[u] + time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};