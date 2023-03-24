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
    void dfs(TreeNode* node, vector<int>& elements){
        if (!node) return;
        dfs(node -> left, elements);
        elements.push_back(node -> val);
        dfs(node -> right, elements);
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> elements;
        dfs(root, elements);
        int prev = elements.back();
        elements.pop_back();
        int answer = INT_MAX;
        while (!elements.empty()){
            int curr = elements.back();
            elements.pop_back();
            answer = min(answer, abs(prev - curr));
            prev = curr;
        }
        return answer;
    }
};