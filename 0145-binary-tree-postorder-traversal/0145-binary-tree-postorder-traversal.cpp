/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void reverseSubtreeLinks(TreeNode* startNode, TreeNode* endNode){
        // If the start and end nodes are the same, no need to traverse.
        if (startNode == endNode)
            return;
        
        TreeNode* prev = nullptr, *curr = startNode, *next = nullptr;
        
        // Reverse the direction of the pointers in the subtree.
        while (curr != endNode){
            next = curr -> right;
            curr -> right = prev;
            prev = curr;
            curr = next;
        }
        
        // Reverse the last node.
        curr -> right = prev;
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // If the root is nullptr, return the empty vector
        if (!root) return {};
        
        vector<int> ans;
        
        // Create a dummy node to simplify edge cases
        TreeNode* dummy = new TreeNode(-1);
        dummy -> left = root;
        root = dummy;
        
        // Traverse the tree
        while (root){
            // If the current node has a left child
            if (root -> left){
                TreeNode* predecessor = root -> left;
                
                // Find the rightmost node in the left subtree or the thread back to the current node
                while (predecessor -> right && predecessor -> right != root)
                    predecessor = predecessor -> right;
                
                // Create a thread if it doesn't exist
                if (predecessor -> right == nullptr){
                    predecessor -> right = root;
                    root = root -> left;
                }
                else{
                    // Process the nodes in the left subtree
                    TreeNode* node = predecessor;
                    reverseSubtreeLinks(root -> left, predecessor);
                    
                    // Add nodes from right to left
                    while (node != root -> left){
                        ans.push_back(node -> val);
                        node = node -> right;
                    }
                    
                    // Add root -> left's value
                    ans.push_back(node -> val);
                    reverseSubtreeLinks(predecessor, root -> left);
                    predecessor -> right = nullptr;
                    root = root -> right;
                }
            }
            else
                // Move to the right child if there's no left child
                root = root -> right;
        }
        
        return ans;
    }
};