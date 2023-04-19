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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 0});
        
        while (!queue.empty()){
            int sz = queue.size();
            stack<int> stack;
            
            for (int i = 0; i < sz; ++i){
                auto [node, level] = queue.front();
                queue.pop();
                
                if (level % 2 == 0){
                    if (node -> val % 2 == 0 || (!stack.empty() && node -> val - stack.top() <= 0))
                        return false;
                    else
                        stack.push(node -> val);
                }
                else{
                    if (node -> val % 2 == 1 || (!stack.empty() && node -> val - stack.top() >= 0))
                        return false;
                    else
                        stack.push(node -> val);
                }
                
                if (node -> left) queue.push({node -> left, level + 1});
                if (node -> right) queue.push({node -> right, level + 1});
            }
        }
        
        return true;
    }
};