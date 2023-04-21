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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stack1, stack2;
        vector<int> ans;
        
        while (!stack1.empty() || !stack2.empty() || root1 || root2){
            while (root1){
                stack1.push(root1);
                root1 = root1 -> left;
            }
            
            while (root2){
                stack2.push(root2);
                root2 = root2 -> left;
            }
            
            if (stack2.empty() || !stack1.empty() && (stack1.top() -> val <= stack2.top() -> val)){
                root1 = stack1.top();
                ans.push_back(root1 -> val);
                stack1.pop();
                root1 = root1 -> right;
            }
            else{
                root2 = stack2.top();
                ans.push_back(root2 -> val);
                stack2.pop();
                root2 = root2 -> right;
            }
            
        }
        
        return ans;
    }
};