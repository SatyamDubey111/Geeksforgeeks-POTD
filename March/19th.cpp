#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    // Custom structure to pass multiple values up the recursive call stack
    struct SubtreeInfo {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };

    SubtreeInfo largestBSTHelper(Node* root) {
        // Base Case: An empty tree is a valid BST of size 0.
        // We return INT_MAX for minVal and INT_MIN for maxVal so parent nodes easily pass the comparison test.
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Post-order traversal: Get info from left and right children first
        SubtreeInfo leftInfo = largestBSTHelper(root->left);
        SubtreeInfo rightInfo = largestBSTHelper(root->right);

        // Check if the current subtree forms a valid BST
        if (leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.maxVal && root->data < rightInfo.minVal) {
            
            // It is a valid BST! Calculate combined size, and new min/max values.
            int currentSize = leftInfo.size + rightInfo.size + 1;
            int currentMin = min(root->data, leftInfo.minVal);
            int currentMax = max(root->data, rightInfo.maxVal);
            
            return {true, currentSize, currentMin, currentMax};
        }

        // If it's NOT a valid BST, we just pass up the size of the largest valid BST we found lower down.
        // We set isBST to false. The minVal and maxVal don't matter anymore, so we can just pass 0.
        return {false, max(leftInfo.size, rightInfo.size), 0, 0};
    }

public:
    // Main function called by the driver code
    int largestBst(Node *root) {
        return largestBSTHelper(root).size;
    }
};