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
    void traverseTree(TreeNode* curr, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& graph, unordered_set<TreeNode*>& leaves){
        if (!curr) return;
        
        if (!(curr -> left || curr -> right)){
            leaves.insert(curr);                                      
        }
        
        if (prev){
            graph[prev].push_back(curr);
            graph[curr].push_back(prev);
        }
        
        traverseTree(curr -> left, curr, graph, leaves);
        traverseTree(curr -> right, curr, graph, leaves);
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leaves;
        traverseTree(root, nullptr, graph, leaves);
        int ans = 0;
        
        for (TreeNode* leaf : leaves){
            queue<TreeNode*> queue;
            queue.push(leaf);
            unordered_set<TreeNode*> seen;
            seen.insert(leaf);
            
            // Go through all nodes that are within the given distance of
            // the current leaf node.
            for (int i = 0; i <= distance; ++i){
                int sz = queue.size();
                
                for (int j = 0; j < sz; ++j){
                    TreeNode* curr = queue.front(); queue.pop();
                    
                    if (leaves.count(curr) && curr != leaf) ++ ans;
                    
                    if (graph.count(curr)){
                        for (TreeNode* neighbor : graph[curr]){
                            if (!seen.count(neighbor)){
                                seen.insert(neighbor);
                                queue.push(neighbor);
                            }
                        }
                    }
                }
            }
        }
        
        return ans >> 1;
    }
};