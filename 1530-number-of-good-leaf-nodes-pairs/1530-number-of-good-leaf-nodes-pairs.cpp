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
    vector<int> postOrder(TreeNode* curr, int distance){
        if (!curr)
            return vector<int>(12);
        
        if (!(curr -> left || curr -> right)){
            vector<int> current(12);
            // Leaf node's distance from itself is 0
            current[0] = 1;
            return current;
        }
        
        // Leaf node count for a given distance i
        vector<int> left = postOrder(curr -> left, distance);
        vector<int> right = postOrder(curr -> right, distance);
        
        vector<int> current(12);
        
        // Combine the counts from the left and right subtree and shift by
        // + 1 distance
        for (int i = 0; i < 10; ++i){
            current[i + 1] = left[i] + right[i];
        }
        
        // Intialize to total number of good leaf nodes pairs from left and
        // right subtrees.
        current[11] += left[11] + right[11];
        
        // Iterate through possible leaf node distance pairs
        for (int d1 = 0; d1 <= distance; ++d1){
            for (int d2 = 0; d2 <= distance; ++d2){
                if (2 + d1 + d2 <= distance){
                    // If the total path distance is less than the given
                    // distance limit, then add to the total number of good
                    // pairs.
                    current[11] += left[d1] * right[d2];
                }
            }
        }
        
        return current;
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        return postOrder(root, distance)[11];
    }
};