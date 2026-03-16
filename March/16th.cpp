#include <unordered_map>
using namespace std;

class Solution {
public:
    int solve(Node* root, int k, long long current_sum, unordered_map<long long, int>& prefix_sums) {
        if (!root) return 0;

        current_sum += root->data;
        int count = 0;
        
        if (prefix_sums.find(current_sum - k) != prefix_sums.end()) {
            count = prefix_sums[current_sum - k];
        }

        prefix_sums[current_sum]++;
        
        count += solve(root->left, k, current_sum, prefix_sums);
        count += solve(root->right, k, current_sum, prefix_sums);

        prefix_sums[current_sum]--;
        
        return count;
    }

    int countAllPaths(Node* root, int k) {
        unordered_map<long long, int> prefix_sums;
        prefix_sums[0] = 1;
        return solve(root, k, 0, prefix_sums);
    }
};