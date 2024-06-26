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
    void inorder(TreeNode* node, vector<int>& traversal){
        // Perform an inorder traversal to store the elements in sorted order
        if (!node) return;
        inorder(node -> left, traversal);
        traversal.push_back(node -> val);
        inorder(node -> right, traversal);
    }
    
    TreeNode* createBalancedTree(vector<int>& inorderTraversal, int start, int end){
        // Base case: If the start index is greater than the end index, return
        // nullptr
        if (start > end) return nullptr;
        
        // Find the middle element of the current range
        int mid = start + ((end - start) >> 1);
        
        // Recursively construct the left and right subtrees
        TreeNode* leftSubtree = createBalancedTree(inorderTraversal, start, mid - 1);
        TreeNode* rightSubtree = createBalancedTree(inorderTraversal, mid + 1, end);
        
        // Create a new node with the middle element and attach the subtrees
        return new TreeNode(inorderTraversal[mid], leftSubtree, rightSubtree);
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        // Create a vector to store the inorder traversal of the BST
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);
        int n = inorderTraversal.size();
        
        // Construct and return the balanced tree
        return createBalancedTree(inorderTraversal, 0, n - 1);
    }
};