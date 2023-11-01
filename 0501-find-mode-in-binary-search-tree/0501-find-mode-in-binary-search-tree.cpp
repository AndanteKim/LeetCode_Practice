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
    int maxStreak = 0, currStreak = 0, currNum = 0;
    void add(int num, vector<int>& ans){
        if (num == currNum)
            ++currStreak;
        else{
            currStreak = 1;
            currNum = num;
        }
        
        if (currStreak > maxStreak){
            ans = {};
            maxStreak = currStreak;
        }
        
        if (currStreak == maxStreak)
            ans.push_back(num);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr){
            if (curr -> left){
                TreeNode* friendNode = curr -> left;
                while (friendNode -> right && friendNode -> right != curr)
                    friendNode = friendNode -> right;
                
                if (!friendNode -> right){
                    friendNode -> right = curr;
                    curr = curr -> left;
                }
                else{
                    friendNode -> right = nullptr;
                    add(curr -> val, ans);
                    curr = curr -> right;
                }
            }
            else{
                add(curr -> val, ans);
                curr = curr -> right;
            }
        }
        
        return ans;
    }
};