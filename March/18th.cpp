class Solution {
public:
    int moves = 0;

    // Helper function returns the "balance" of candies at a node
    int traverse(Node* root) {
        if (!root) return 0;

        // Calculate excess/deficit from left and right subtrees
        int leftBalance = traverse(root->left);
        int rightBalance = traverse(root->right);

        // Moves needed is the absolute sum of balances
        moves += abs(leftBalance) + abs(rightBalance);

        // Return current node's balance: (current + children) - 1 (for itself)
        return root->data + leftBalance + rightBalance - 1;
    }

    int distCandy(Node* root) {
        moves = 0;
        traverse(root);
        return moves;
    }
};