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
private:
    int k;
    void buildGraph(TreeNode* child, TreeNode* parent, unordered_map<int, vector<int>>& graph){
        if (child && parent){
            graph[child -> val].push_back(parent -> val);
            graph[parent -> val].push_back(child -> val);
        }
        
        if (child -> left) buildGraph(child -> left, child, graph);
        if (child -> right) buildGraph(child -> right, child, graph);
    }
    
    void dfs(int curr, int dist, vector<int>& ans, unordered_set<int>& visited, unordered_map<int, vector<int>>& graph){
        if (dist == this -> k){
            ans.push_back(curr);
            return;
        }
        
        for (int neighbor : graph[curr]){
            if (visited.find(neighbor) == visited.end()){
                visited.insert(neighbor);
                dfs(neighbor, dist + 1, ans, visited, graph);
            }
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this -> k = k;
        unordered_map<int, vector<int>> graph;
        buildGraph(root, nullptr, graph);
        
        vector<int> ans;
        unordered_set<int> visited{{target -> val}};
        dfs(target -> val, 0, ans, visited, graph);
        return ans;
    }
};