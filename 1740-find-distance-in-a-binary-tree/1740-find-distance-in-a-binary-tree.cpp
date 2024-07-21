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
    TreeNode* findLCA(TreeNode* root, int p, int q){
        if (!root || root -> val == p || root -> val == q)
            return root;
        
        TreeNode* left = findLCA(root -> left, p, q);
        TreeNode* right = findLCA(root -> right, p, q);
        
        if (left && right)
            return root;
        
        return left? left : right;
    }
    
public:
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* lca = findLCA(root, p, q);
        
        queue<TreeNode*> queue;
        queue.push(lca);
        int dist = 0, depth = 0;
        bool foundP = false, foundQ = false;
        
        while (!queue.empty() && !(foundP && foundQ)){
            int sz = queue.size();
            
            for (int i = 0; i < sz; ++i) {
                // Dequeue the node
                TreeNode* node = queue.front(); queue.pop();
            
                if (node -> val == p){
                    dist += depth;
                    foundP = true;
                }
            
                if (node -> val == q){
                    dist += depth;
                    foundQ = true;
                }
                
                // Enqueue the left child
                if (node -> left) queue.push(node -> left);
                
                // Enqueue the right child
                if (node -> right) queue.push(node -> right);
            }
            ++depth;
        }
        
        return dist;
    }
};