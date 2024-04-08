class Solution {
private:
    bool helper(int &i, vector<int>& preorder, int minLimit, int maxLimit){
        if (i == preorder.size())
            return true;
        
        int root = preorder[i];
        if (preorder[i] <= minLimit || preorder[i] >= maxLimit) return false;
        ++i;
        bool left = helper(i, preorder, minLimit, root);
        bool right = helper(i, preorder, root, maxLimit);
        return left || right;
    }
    
public:
    bool verifyPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(i, preorder, INT_MIN, INT_MAX);
    }
};