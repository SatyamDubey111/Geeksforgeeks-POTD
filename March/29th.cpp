#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int total_sum = 0;
        for (int num : arr) {
            total_sum += num;
        }

        // Check if a valid integer target sum is even mathematically possible
        if (total_sum < diff || (total_sum + diff) % 2 != 0) {
            return 0;
        }

        int target = (total_sum + diff) / 2;

        // dp[j] stores the number of subsets that sum up to 'j'
        vector<int> dp(target + 1, 0);
        
        // Base case: There is 1 way to make a sum of 0 (by choosing an empty subset)
        dp[0] = 1;

        // Populate the DP table
        for (int num : arr) {
            // Traverse backwards to avoid using the same element multiple times
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] + dp[j - num];
            }
        }

        return dp[target];
    }
};