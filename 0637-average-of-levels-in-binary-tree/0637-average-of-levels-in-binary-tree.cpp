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
#define ll long long

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            ll curr = 0;
            int sz = queue.size();
            
            for (int i = 0; i < sz; ++i){
                TreeNode* node = queue.front();
                queue.pop();
                curr += node -> val;
                
                if (node -> left) queue.push(node -> left);
                if (node -> right) queue.push(node -> right);
            }
            ans.push_back((double) curr / sz);
        }
        
        return ans;
    }
};