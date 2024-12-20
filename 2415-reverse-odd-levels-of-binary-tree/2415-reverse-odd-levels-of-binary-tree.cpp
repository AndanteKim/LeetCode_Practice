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
    void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level){
        // Base case
        if (!(leftChild && rightChild)) return;
        
        // If the current level is odd, swap the values of the children 
        if (level % 2 == 0){
            swap(leftChild -> val, rightChild -> val);
        }
        
        traverseDFS(leftChild -> left, rightChild -> right, level + 1);
        traverseDFS(leftChild -> right, rightChild -> left, level + 1);
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        // Base case
        if (!root) return root;
        traverseDFS(root -> left, root -> right, 0);
        
        return root;
    }
};