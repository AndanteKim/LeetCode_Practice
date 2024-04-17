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
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        queue<pair<TreeNode*, string>> queue;
        queue.push({root, ""});
        
        while (!queue.empty()){
            auto [node, curr] = queue.front(); queue.pop();
            curr += (char) 'a' + node -> val;
            
            // If it's leaf
            if (!(node -> left || node -> right)){
                reverse(curr.begin(), curr.end());
                
                if (ans.empty() || ans > curr) ans = curr;
            }
            
            if (node -> left) queue.push({node -> left, curr});
            if (node -> right) queue.push({node -> right, curr});
        }
        
        return ans;
    }
};