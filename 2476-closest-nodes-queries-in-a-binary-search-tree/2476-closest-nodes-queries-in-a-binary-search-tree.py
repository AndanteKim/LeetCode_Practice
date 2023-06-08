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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        
        stack<TreeNode*> stack;
        vector<int> arr;
        TreeNode* tree = root;
        
        while (!stack.empty() || tree){
            if (tree){
                stack.push(tree);
                tree = tree -> left;
            }
            else{
                tree = stack.top();
                stack.pop();
                arr.push_back(tree -> val);
                tree = tree -> right;
            }
        }
        
        int n = arr.size();
        for (int query : queries){
            int pos = lower_bound(arr.begin(), arr.end(), query) - arr.begin();
            if (pos == n) ans.push_back({arr[pos - 1], -1});
            else if (query == arr[pos]) ans.push_back({query, query});
            else if (pos == 0) ans.push_back({-1, arr[pos]});
            else ans.push_back({arr[pos - 1], arr[pos]});
        }
        
        return ans;
    }
};