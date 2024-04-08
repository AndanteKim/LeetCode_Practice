class Solution {
private:
    int i = 0;
    bool helper(vector<int>& preorder, int minLimit, int maxLimit){
        if (i == preorder.size()) return true;
        
        int root = preorder[i];
        if (root < minLimit || root > maxLimit) return false;
        ++i;
        bool left = helper(preorder, minLimit, root);
        bool right = helper(preorder, root, maxLimit);
        return left || right;
    }
    
public:
    bool verifyPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MIN, INT_MAX);
    }
};