#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> result;
        if (!root) return result;

        // map to store {horizontal_distance, vector of node values}
        map<int, vector<int>> hdMap;
        // queue to store {node, horizontal_distance}
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            hdMap[hd].push_back(curr->data);
            
            if (curr->left) {
                q.push({curr->left, hd - 1});
            }
            if (curr->right) {
                q.push({curr->right, hd + 1});
            }
        }
        
        // Push each column vector into the final 2D result
        for (auto& entry : hdMap) {
            result.push_back(entry.second);
        }
        
        return result;
    }
};