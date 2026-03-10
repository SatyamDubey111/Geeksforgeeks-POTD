#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long total_count = 0;
        
        // Stack to store indices of the array
        stack<int> st;

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            
            // We are looking for the next STRICTLY smaller element.
            // Therefore, we pop elements that are greater than or equal to arr[i].
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // If the stack is empty, there is no smaller element to the right.
            // The valid subarrays can extend to the very end of the array.
            long long nse_index = st.empty() ? n : st.top();
            
            // The number of valid subarrays starting at index i
            total_count += (nse_index - i);

            // Push the current index onto the stack for future elements
            st.push(i);
        }

        return total_count;
    }
};