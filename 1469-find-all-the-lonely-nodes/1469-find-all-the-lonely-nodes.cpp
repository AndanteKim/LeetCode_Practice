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
    vector<int> getLonelyNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> queue{{{root, false}}};
        vector<int> ans;
        
        while(!queue.empty()){
            auto [currNode, isLonely] = queue.front(); queue.pop();
        
            if (isLonely) ans.push_back(currNode -> val);
            
            if (currNode -> left) queue.push({currNode -> left, currNode -> right == nullptr});
            
            if (currNode -> right) queue.push({currNode -> right, currNode -> left == nullptr});
        }
        
        return ans;
    }
};