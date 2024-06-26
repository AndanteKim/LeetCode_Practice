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
public:
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return nullptr;
        
        // Step1: Create a backbone (vine)
        // Temporary dummy node
        TreeNode* vineHead = new TreeNode();
        vineHead -> right = root;
        TreeNode* curr = vineHead;
        while (curr -> right){
            if (curr -> right -> left)
                rightRotate(curr, curr -> right);
            else
                curr = curr -> right;
        }
        
        // Step2: Count the nodes
        int nodeCount = 0;
        curr = vineHead -> right;
        while (curr){
            ++nodeCount;
            curr = curr -> right;
        }
        
        // Step3: Create a balanced BST
        int m = pow(2, floor(log2(nodeCount + 1))) - 1;
        makeRotations(vineHead, nodeCount - m);
        while (m > 1){
            m >>= 1;
            makeRotations(vineHead, m);
        }
        
        TreeNode* balancedRoot = vineHead -> right;
        // Delete the temporary dummy node
        delete vineHead;
        return balancedRoot;
    }
    
private:
    // Function to perform a right rotation
    void rightRotate(TreeNode* parent, TreeNode* node){
        TreeNode* tmp = node -> left;
        node -> left = tmp -> right;
        tmp -> right = node;
        parent -> right = tmp;
    }
    
    // Function to perform a left rotation
    void leftRotate(TreeNode* parent, TreeNode* node){
        TreeNode* tmp = node -> right;
        node -> right = tmp -> left;
        tmp -> left = parent -> right;
        parent -> right = tmp;
    }
    
    // Function to perform a series of left rotations to balance the vine
    void makeRotations(TreeNode* vineHead, int count){
        TreeNode* curr = vineHead;
        for (int i = 0; i < count; ++i){
            TreeNode* tmp = curr -> right;
            leftRotate(curr, tmp);
            curr = curr -> right;
        }
    }
};