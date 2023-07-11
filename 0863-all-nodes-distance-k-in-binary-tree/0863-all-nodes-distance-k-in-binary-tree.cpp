/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) return vector<int>{target -> val};
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        queue<pair<TreeNode*, TreeNode*>> graphQ;
        graphQ.push({root, nullptr});
        unordered_set<int> visited;
        visited.insert(target -> val);
        while (!graphQ.empty()){
            auto [child, parent] = graphQ.front();
            graphQ.pop();
            graph[child].push_back(parent);
            graph[parent].push_back(child);
            
            if (child -> left) graphQ.push({child -> left, child});
            if (child -> right) graphQ.push({child -> right, child});
        }
        
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        while (!q.empty()){
            auto [node, level] = q.front();
            q.pop();
            
            if (level == k) {
                ans.push_back(node -> val);
                continue;
            }
            
            for (TreeNode* neighbor : graph[node]){
                if (neighbor && visited.find(neighbor -> val) == visited.end()){
                    visited.insert(neighbor -> val);
                    q.push({neighbor, level + 1});
                }
            }
        }
        
        return ans;
    }
};