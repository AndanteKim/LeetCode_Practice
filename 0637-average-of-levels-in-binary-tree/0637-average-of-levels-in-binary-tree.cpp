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
    void average(TreeNode* t, int i, vector<double>& total, vector<int>& count){
        if (!t) return;
        
        if (i < total.size()){
            total[i] += t -> val;
            ++count[i];
        }
        else{
            total.push_back(t -> val);
            count.push_back(1);
        }
        
        average(t -> left, i + 1, total, count);
        average(t -> right, i + 1, total, count);
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<int> count;
        
        average(root, 0, res, count);
        int sz = res.size();
        for (int i = 0; i < sz; ++i) res[i] /= count[i];
        
        return res;
    }
};