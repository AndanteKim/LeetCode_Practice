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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        stack<pair<TreeNode*, bool>> *st = new stack<pair<TreeNode*, bool>>;
        st -> push({root, false});
        unordered_map<TreeNode*, int> height;
        
        while (!st -> empty()){
            auto[node, seen] = st -> top();
            
            if (!seen){
                st -> top().second = true;
                
                if (node -> left) st -> push({node -> left, false});
                if (node -> right) st -> push({node -> right, false});
            }
            else{
                int left = height[node -> left], right = height[node -> right];
                diameter = max(diameter, left + right);
                height[node] = max(left, right) + 1;
                st -> pop();
            }
        }
        
        
        return diameter;
    }
};