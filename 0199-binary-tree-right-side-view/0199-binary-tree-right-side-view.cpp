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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> *q = new queue<TreeNode*>;
        vector<int> answer;
        q -> push(root);
        while (!q -> empty()){
            int level = q -> size();
            TreeNode* node;
            for (int i = 0; i < level; ++i){
                node = q -> front();
                q -> pop();
                
                if (node -> left) q -> push(node -> left);
                if (node -> right) q -> push(node -> right);
            }
            answer.push_back(node -> val);
        }
        
        return answer;
    }
};