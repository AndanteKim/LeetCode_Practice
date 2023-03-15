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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> *q = new queue<TreeNode*>;
        q -> push(root);
        
        bool nodeNullFound = false;
        while (!q -> empty()){
            TreeNode* node = q -> front();
            q -> pop();
            
            if (node == nullptr) nodeNullFound = true;
            else{
                if (nodeNullFound) return false;
                q -> push(node -> left);
                q -> push(node -> right);
            }
        }
        
        return true;
    }
};