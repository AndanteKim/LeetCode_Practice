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
        int root_to_leaf = 0;
        stack<pair<TreeNode*, int>> *st = new stack<pair<TreeNode*, int>>;
        st -> push({root, 0});
        
        while (!st -> empty()){
            TreeNode* node = st -> top().first;
            int curr_number = st -> top().second;
            st -> pop();
            
            if (node != nullptr){
                curr_number = curr_number * 10 + node -> val;
                if (!node -> left && !node -> right) root_to_leaf += curr_number;
                else{
                    st -> push({node -> left, curr_number});
                    st -> push({node -> right, curr_number});
                }
            }
        }
        
        return root_to_leaf;
    }
};