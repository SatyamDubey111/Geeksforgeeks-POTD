class Solution {
private:
    // Helper function to map parents and find the target node pointer
    Node* mapParentsAndFindTarget(Node* root, unordered_map<Node*, Node*>& parentMap, int target) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = NULL;
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            // Capture the target node when we find it
            if (current->data == target) {
                targetNode = current;
            }
            
            // Map left child to current node and push to queue
            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            // Map right child to current node and push to queue
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
        return targetNode;
    }

public:
    int minTime(Node* root, int target) {
        if (!root) return 0;
        
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = mapParentsAndFindTarget(root, parentMap, target);
        
        // Edge case: if target is not found
        if (!targetNode) return 0;
        
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        
        // Start the fire at the target node
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        // BFS to spread the fire
        while (!q.empty()) {
            int size = q.size();
            bool fireSpread = false; // Flag to check if fire actually spread in this second
            
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                
                // 1. Spread to the left child
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                    fireSpread = true;
                }
                
                // 2. Spread to the right child
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                    fireSpread = true;
                }
                
                // 3. Spread to the parent
                if (parentMap[current] && !visited[parentMap[current]]) {
                    q.push(parentMap[current]);
                    visited[parentMap[current]] = true;
                    fireSpread = true;
                }
            }
            // If fire spread to any new node, increment the timer
            if (fireSpread) {
                time++;
            }
        }
        
        return time;
    }
};