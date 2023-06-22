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
class BSTIterator{
public:
    TreeNode* curr;
    BSTIterator(TreeNode* root){
        curr = root;
    }
    
    void morris(int flag){
        while (curr){
            if (curr -> left){
                TreeNode* rightMost = curr -> left;
                while (rightMost -> right && rightMost -> right != curr){
                    rightMost = rightMost -> right;
                }
                
                if (rightMost -> right == curr){
                    if (flag) rightMost -> right = NULL;
                    break;
                }
                else{
                    rightMost -> right = curr;
                    curr = curr -> left;
                }
            }
            else break;
        }
    }
    
    int peek(){
        morris(0);
        return curr -> val;
    }
    
    void increment(){
        morris(1);
        curr = curr -> right;
    }
    
    bool hasNext(){
        return curr != NULL;
    }
    
};

class rBSTIterator{
public:
    TreeNode* curr;
    rBSTIterator(TreeNode* root){
        curr = root;
    }
    
    void morris(int flag){
        while (curr){
            if (curr -> right){
                TreeNode* leftMost = curr -> right;
                while (leftMost -> left && leftMost -> left != curr){
                    leftMost = leftMost -> left;
                }
                
                if (leftMost -> left == curr){
                    if (flag) leftMost -> left = NULL;
                    break;
                }
                else{
                    leftMost -> left = curr;
                    curr = curr -> right;
                }
            }
            else break;
        }
    }
    
    int peek(){
        morris(0);
        return curr -> val;
    }
    
    void decrement(){
        morris(1);
        curr = curr -> left;
    }
    
    bool hasPrev(){
        return curr != NULL;
    }
    
};

class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        BSTIterator it1(root1);
        rBSTIterator it2(root2);
        bool found = false;
        
        while(it1.hasNext() && it2.hasPrev()){
            int x = it1.peek(), y = it2.peek();
            if (x + y == target){
                found = true;
                break;
            }
            if (x + y < target) it1.increment();
            else it2.decrement();
        }
        
        while (it1.hasNext()) it1.increment();
        while (it2.hasPrev()) it2.decrement();
        
        return found;
    }
};