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
    vector<int> IterativeInorder(TreeNode* node){
        stack<TreeNode*> *st = new stack<TreeNode*>;
        vector<int> values;
        TreeNode* curr = node;
        
        while (!st -> empty() || curr){
            if (curr){
                st -> push(curr);
                curr = curr -> left;
            }
            else{
                curr = st -> top();
                st -> pop();
                values.push_back(curr -> val);
                curr = curr -> right;
            }
        }
        return values;
    } 
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> values = IterativeInorder(root);
        int ans = INT_MAX;
        for (int i = 1; i < values.size(); ++i){
            ans = min(ans, values[i] - values[i - 1]);
        }
        return ans;
    }
};