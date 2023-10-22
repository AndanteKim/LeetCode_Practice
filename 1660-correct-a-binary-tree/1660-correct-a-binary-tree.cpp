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
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        
        while (!q.empty()){
            int n = q.size();
            unordered_set<TreeNode*> seen;
            for (int i = 0 ; i < n; ++i){
                auto [child, parent] = q.front();
                q.pop();
                
                if(seen.find(child -> right) != seen.end()){
                    if (parent -> left == child)
                        parent -> left = nullptr;
                    else
                        parent -> right = nullptr;
                    return root;
                }
                
                seen.insert(child);
                if (child -> right)
                    q.push({child -> right, child});
                if (child -> left)
                    q.push({child -> left, child});
            }
        }
        return root;
    }
};