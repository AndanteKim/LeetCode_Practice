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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> *q = new queue<TreeNode*>;
        q -> push(root);
        q -> push(root);
        
        while(!q -> empty()){
            TreeNode* t1 = q -> front();
            q -> pop();
            TreeNode* t2 = q -> front();
            q -> pop();
            
            if (!t1 && !t2) continue;
            if (!t1 || !t2) return false;
            if (t1 -> val != t2 -> val) return false;
            q -> push(t1 -> left);
            q -> push(t2 -> right);
            q -> push(t1 -> right);
            q -> push(t2 -> left);
        }
        
        return true;
    }
};