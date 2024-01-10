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
    void convert(TreeNode* current, int parent, unordered_map<int, unordered_set<int>>& treeMap){
        if (!current)
            return;
        
        unordered_set<int> &adjList = treeMap[current -> val];
        if (parent != 0)
            adjList.insert(parent);
        
        if (current -> left)
            adjList.insert(current -> left -> val);
        
        if (current -> right)
            adjList.insert(current -> right -> val);
        
        convert(current -> left, current -> val, treeMap);
        convert(current -> right, current -> val, treeMap);
    }
    
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> treeMap;
        convert(root, 0, treeMap);
        
        queue<int> q{{start}};
        int ans = 0;
        unordered_set<int> visited{start};
        
        while (!q.empty()){
            int level = q.size();
            while (level > 0){
                int current = q.front();
                q.pop();
                
                for (int num: treeMap[current]){
                    if (!visited.count(num)){
                        visited.insert(num);
                        q.push(num);
                    }
                }
                --level;
            }
            ++ans;
        }
        
        return ans - 1;
    }
};