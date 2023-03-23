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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        
        queue<TreeNode*> *q = new queue<TreeNode*>;
        q -> push(root);
        int maxNumForLevel = INT_MIN;
        vector<int> ans;
        
        while(!q -> empty()){
            int level = q -> size();
            maxNumForLevel = INT_MIN;
            for (int i = 0; i < level; ++i){
                TreeNode* node = q -> front();
                q -> pop();
                
                maxNumForLevel = max(maxNumForLevel, node -> val);
                if (node -> left) q -> push(node -> left);
                if (node -> right) q -> push(node -> right);
            }
            ans.push_back(maxNumForLevel);
        }
        return ans;
    }
};