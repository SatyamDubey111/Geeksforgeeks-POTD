#include <vector>

using namespace std;

class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int flipCount = 0;
        int currentFlips = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                currentFlips ^= isFlipped[i - k];
            }
            
            if (arr[i] == currentFlips) {
                if (i + k > n) {
                    return -1;
                }
                isFlipped[i] = 1;
                currentFlips ^= 1;
                flipCount++;
            }
        }
        
        return flipCount;
    }
};