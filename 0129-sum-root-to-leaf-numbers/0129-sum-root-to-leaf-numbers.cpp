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
    int sumNumbers(TreeNode* root) {
        int root_to_leaf = 0, curr_number = 0, steps;
        TreeNode* predecessor;
        while(root){
            if (root -> left){
                predecessor = root -> left;
                steps = 1;
                while (predecessor -> right && predecessor -> right != root){
                    predecessor = predecessor -> right;
                    ++steps;
                }
                if (!predecessor -> right){
                    curr_number = curr_number * 10 + root -> val;
                    predecessor -> right = root;
                    root = root -> left;
                }
                else{
                    if (!predecessor -> left) root_to_leaf += curr_number;
                    
                    for (int i = 0; i < steps; ++i) curr_number /= 10;
                    predecessor -> right = nullptr;
                    root = root -> right;
                }
            }
            else{
                curr_number = curr_number * 10 + root -> val;
                if (!root -> right) root_to_leaf += curr_number;
                root = root -> right;
            }
        }
        return root_to_leaf;
    }
};