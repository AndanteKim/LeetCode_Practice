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
private:
    vector<pair<int, int>> bfs(TreeNode* root){
        vector<vector<pair<int, int>>> treeSet;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<pair<int, int>> interSet;
            for (int i = 0; i < sz; ++i){
                TreeNode* node = q.front(); q.pop();

                interSet.push_back({depth, node -> val});
                if (node -> left)
                    q.push(node -> left);
                
                if (node -> right)
                    q.push(node -> right);
            }

            treeSet.push_back(interSet);
            ++depth;
        }

        return treeSet.back();
    }
    
    TreeNode* lca(TreeNode* node, int a, int b){
        if (!node || node -> val == a || node -> val == b) return node;

        TreeNode* left = lca(node -> left, a, b);
        TreeNode* right = lca(node -> right, a, b);
        
        if (!left) return right;
        else if (!right) return left;
        return node;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<pair<int, int>> lastDeepest = bfs(root);
        int a = lastDeepest[0].second, b = lastDeepest.back().second;
        return lca(root, a, b);
    }
};