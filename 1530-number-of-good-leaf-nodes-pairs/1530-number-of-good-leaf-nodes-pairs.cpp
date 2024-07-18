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
    void findAncestor(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& ancestors){
        if (!node) return;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({node, nullptr});
        
        while (!q.empty()){
            auto [child, parent] = q.front(); q.pop();
            
            ancestors[child] = parent;
            
            if (child -> left)
                q.push({child -> left, child});
            
            if (child -> right)
                q.push({child -> right, child});
        }
        
    }
    
    void findLeaves(TreeNode* node, unordered_set<TreeNode*>& leaves){
        if (!node) return;
        
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()){
            auto curr = q.front(); q.pop();
            
            if (!(curr -> left || curr -> right))
                leaves.insert(curr);
            
            if (curr -> left)
                q.push(curr -> left);
            
            if (curr -> right)
                q.push(curr -> right);
        }
    }
    
    
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, TreeNode*> ancestors;
        unordered_set<TreeNode*> leaves;
        unordered_map<TreeNode*, unordered_set<TreeNode*>> pairs;
        findAncestor(root, ancestors);
        findLeaves(root, leaves);
        int ans = 0;
        
        for (TreeNode* node : leaves){
            TreeNode* origin = node;
            int start = distance;
            
            while (start > 0 && node){
                queue<pair<TreeNode*, int>> q;
                q.push({node, start});
                
                while (!q.empty()){
                    auto [curr, remain] = q.front(); q.pop();
                    
                    if (origin != curr && leaves.count(curr) && !pairs[origin].count(curr)){
                        pairs[origin].insert(curr);
                        ++ans;
                        continue;
                    }
                    
                    if (remain == 0) continue;
                    
                    if (curr -> left) q.push({curr -> left, remain - 1});
                    
                    if (curr -> right) q.push({curr -> right, remain - 1});
                }
                
                node = ancestors[node];
                --start;
            }
        }
        
        return ans >> 1;
    }
};