class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;

        // 1. Find Predecessor (Largest value strictly less than key)
        Node* curr = root;
        while (curr != NULL) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        // 2. Find Successor (Smallest value strictly greater than key)
        curr = root;
        while (curr != NULL) {
            if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        // Return as a vector containing two pointers
        return {pre, suc};
    }
};