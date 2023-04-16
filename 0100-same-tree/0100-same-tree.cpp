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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q)) return false;
        
        queue<pair<TreeNode*, TreeNode*>> queue;
        queue.push(make_pair(p, q));
        
        while (!queue.empty()){
            auto[p_derive, q_derive] = queue.front();
            queue.pop();
            
            if (p_derive -> val != q_derive -> val) return false;
            
            if (p_derive -> left && q_derive -> left) queue.push(make_pair(p_derive -> left, q_derive -> left));
            else if ((!p_derive -> left && q_derive -> left) || (p_derive -> left && !q_derive -> left)) return false;
            
            if (p_derive -> right && q_derive -> right) queue.push(make_pair(p_derive -> right, q_derive -> right));
            else if ((!p_derive -> right && q_derive -> right) || (p_derive -> right && !q_derive -> right)) return false;
        }
        
        return true;
    }
};