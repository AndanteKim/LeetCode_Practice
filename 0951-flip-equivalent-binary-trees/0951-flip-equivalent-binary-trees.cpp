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
    void findCanonicalForm(TreeNode* node){
        if (!node) return;
        
        // Post-order traversal: First bring subtress in their canonical form
        findCanonicalForm(node -> left);
        findCanonicalForm(node -> right);
        
        if (!node -> right) return;
        
        // Swap subtrees, so that left is non-empty
        if (!node -> left){
            node -> left = node -> right;
            node -> right = nullptr;
            return;
        }
        
        TreeNode* left = node -> left;
        TreeNode* right = node -> right;
        
        // Swap subtrees
        if (left -> val > right -> val){
            swap(node -> left, node -> right);
        }
    }
    
    bool areEquivalent(TreeNode* node1, TreeNode* node2){
        if (!(node1 || node2)) return true;
        if (!(node1 && node2)) return false;
        if (node1 -> val != node2 -> val) return false;
        
        return areEquivalent(node1 -> left, node2 -> left) && areEquivalent(node1 -> right, node2 -> right);
    }
    
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        findCanonicalForm(root1);
        findCanonicalForm(root2);
        
        return areEquivalent(root1, root2);
    }
};