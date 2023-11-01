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
    void dfs(TreeNode* node, vector<int>& values){
        if (!node)
            return;
        
        dfs(node -> left, values);
        values.push_back(node -> val);
        dfs(node -> right, values);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> values, ans;
        dfs(root, values);
        
        int currStreak = 0, maxStreak = 0, currVal = 0;
        for (int num : values){
            if (num == currVal)
                ++currStreak;
            else{
                currStreak = 1;
                currVal = num;
            }
            
            if (currStreak > maxStreak){
                maxStreak = currStreak;
                ans.clear();
            }
            
            if (currStreak == maxStreak)
                ans.push_back(currVal);
        }
        
        return ans;
    }
};