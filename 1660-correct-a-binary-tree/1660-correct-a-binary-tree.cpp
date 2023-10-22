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
        unordered_map<TreeNode*, TreeNode*> ancestors;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        
        while(!q.empty()){
            auto[child, parent] = q.front();
            q.pop();
            
            if (ancestors.find(child) != ancestors.end()){
                if (!ancestors[parent]) return nullptr;
                if (ancestors[parent] -> left == parent)
                    ancestors[parent] -> left = nullptr;
                else
                    ancestors[parent] -> right = nullptr;
                break;
            }
            ancestors[child] = parent;
            if(child -> left)
                q.push({child -> left, child});
            if(child -> right)
                q.push({child -> right, child});
        }
        
        return root;
    }
};