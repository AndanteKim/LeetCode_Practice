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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*> q{{root}};
        unordered_map<int, vector<int>> adj;
        
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if (node -> left){
                adj[node -> val].push_back(node -> left -> val);
                adj[node -> left -> val].push_back(node -> val);
                q.push(node -> left);
            }
            
            if (node -> right){
                adj[node -> val].push_back(node -> right -> val);
                adj[node -> right -> val].push_back(node -> val);
                q.push(node -> right);
            }
        }
        
        int ans = 0;
        vector<bool> visited(100'001);
        queue<pair<int, int>> graphQ;
        graphQ.push(make_pair(start, 0));
        while(!graphQ.empty()){
            auto [node, dist] = graphQ.front();
            graphQ.pop();
            
            if (!visited[node]){
                ans = max(ans, dist);
                visited[node] = true;
                for (int neighbor: adj[node]){
                    graphQ.push({neighbor, dist + 1});
                }
            }
        }
        
        return ans;
    }
};