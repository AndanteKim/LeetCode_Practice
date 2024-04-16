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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // base case
        if (depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }
        
        queue<tuple<TreeNode*, TreeNode*, int>> queue;
        queue.push({nullptr, root, 1});
        
        while (!queue.empty()){
            auto [parent, curr, currDepth] = queue.front(); queue.pop();
            
            if (parent && currDepth == depth){
                TreeNode* newNode = new TreeNode(val);
                if (parent -> left == curr){
                    parent -> left = newNode;
                    newNode -> left = curr;
                }
                else{
                    parent -> right = newNode;
                    newNode -> right = curr;
                }
                continue;
            }
            
            if (!curr) continue;
            queue.push({curr, curr -> left, currDepth + 1});
            queue.push({curr, curr -> right, currDepth + 1});
        }
        
        return root;
    }
};