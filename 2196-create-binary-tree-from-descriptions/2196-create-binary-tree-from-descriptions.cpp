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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Sets to track unique children and parents
        unordered_set<int> children, parents;
        
        // unordered map to store parent to children relationships
        unordered_map<int, vector<pair<int, int>>> parentToChildren;
        
        // Build a graph from parent to child, and add nodes to hashsets
        for (vector<int>& d : descriptions){
            int parent = d[0], child = d[1], isLeft = d[2];
            children.insert(child);
            parents.insert(parent);
            parents.insert(child);
            parentToChildren[parent].push_back({child, isLeft});
        }
        
        // Find the root node by checking which node is in parents, but not in
        // children
        unordered_set<int> parentsCp(parents.begin(), parents.end());
        for (int p : parentsCp){
            if (children.count(p)){
                parents.erase(p);
            }
        }
        
        TreeNode* root = new TreeNode(*parents.begin());
        
        // Starting from root, use BFS to contsruct binary tree
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            TreeNode* parent = q.front(); q.pop();
            
            // Iterate over children of current parent
            for (auto& [childVal, isLeft] : parentToChildren[parent -> val]){
                TreeNode* child = new TreeNode(childVal);
                
                // Attach child node to its parent based on isLeft flag
                if (isLeft)
                    parent -> left = child;
                else
                    parent -> right = child;
                q.push(child);
            }
        }
        
        return root;
    }
};