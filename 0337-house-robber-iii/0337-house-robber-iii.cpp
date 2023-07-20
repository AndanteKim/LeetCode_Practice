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
    int rob(TreeNode* root) {
        if (!root) return 0;
        vector<int> tree;
        map<int, vector<int>> graph;
        graph[-1] = {};
        int index = -1;
        
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, -1});
        while (!queue.empty()){
            auto [node, parentIndex] = queue.front();
            queue.pop();
            
            if (node){
                ++index;
                tree.push_back(node -> val);
                graph[index] = {};
                graph[parentIndex].push_back(index);
                queue.push({node -> left, index});
                queue.push({node -> right, index});
            }
        }
        
        vector<int> dpRob(index + 1), dpNotRob(index + 1);
        for (int i = index; i >= 0; --i){
            if (graph[i].empty()){
                dpRob[i] = tree[i];
                dpNotRob[i] = 0;
            }
            else{
                dpRob[i] = tree[i];
                for (int child : graph[i]) dpRob[i] += dpNotRob[child];
                for (int child : graph[i]) dpNotRob[i] += max(dpRob[child], dpNotRob[child]);
            }
        }
        
        return max(dpRob[0], dpNotRob[0]);
    }
};