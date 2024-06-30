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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // Base case: if root is nullptr
        if (!root) return vector<TreeNode*>{nullptr, nullptr};
        
        // If the root's val is greater than target
        if (root -> val > target){
            vector<TreeNode*> left = splitBST(root -> left, target);
            root -> left = left[1];
            return vector<TreeNode*>{left[0], root};
        }
        
        // Otherwise, recursively split right subtree.
        else{
            vector<TreeNode*> right = splitBST(root -> right, target);
            root -> right = right[0];
            return vector<TreeNode*>{root, right[1]};
        }
        
        return vector<TreeNode*>{};
    }
};