#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Renamed to 'maxProfit' to match your Driver.cpp
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return 0;

        // Use long long internally to prevent overflow during calculations,
        // then cast back to int for the return type.
        long long hold = -arr[0];
        long long free = 0;

        for (int i = 1; i < n; ++i) {
            long long prev_free = free;
            
            // State transition: Selling
            free = max(free, hold + arr[i] - k);
            
            // State transition: Buying
            hold = max(hold, prev_free - arr[i]);
        }

        return (int)free;
    }
};