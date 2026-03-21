#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * Function to return an array where the ith element denotes the 
     * number of unique BSTs formed when arr[i] is chosen as the root.
     */
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Precompute Catalan numbers up to n.
        // Catalan(n) = sum(Catalan(i) * Catalan(n-1-i)) for i from 0 to n-1.
        vector<int> catalan(n + 1, 0);
        catalan[0] = 1; 
        if (n >= 1) catalan[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - 1 - j];
            }
        }
        
        vector<int> result;
        
        // Step 2: For each element in the array, determine how many 
        // elements would fall into its left and right subtrees.
        for (int i = 0; i < n; i++) {
            int smallerCount = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i]) {
                    smallerCount++;
                }
            }
            
            // Total nodes in left subtree = smallerCount
            // Total nodes in right subtree = (Total elements - 1 for root - smallerCount)
            int largerCount = n - 1 - smallerCount;
            
            // The total unique BSTs = (Ways to form left) * (Ways to form right)
            result.push_back(catalan[smallerCount] * catalan[largerCount]);
        }
        
        return result;
    }
};