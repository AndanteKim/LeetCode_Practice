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
    unordered_map<TreeNode*, TreeNode*> parents;
    
    void dfs(TreeNode* node, TreeNode* parent){
        if (!node) return;
        parents[node] = parent;
        dfs(node -> left, node);
        dfs(node -> right, node);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);
        queue<TreeNode*> *q = new queue<TreeNode*>;
        unordered_set<TreeNode*> *seen = new unordered_set<TreeNode*>;
        int distance = 0;
        q -> push(target);
        seen -> insert(target);
        
        while (!q -> empty() && distance < k){
            int curr_length = q -> size();
            for (int i = 0; i < curr_length; ++i){
                TreeNode* node = q -> front();
                q -> pop();
                for (TreeNode* neighbor : {node -> left, node -> right, parents[node]}){
                    if (neighbor && seen -> find(neighbor) == seen -> end()){
                        seen -> insert(neighbor);
                        q -> push(neighbor);
                    }
                }
            }
            ++distance;
        }
        
        vector<int> ans;
        while (!q -> empty()){
            ans.push_back(q -> front() -> val);
            q -> pop();
        }
        
        return ans;
    }
};