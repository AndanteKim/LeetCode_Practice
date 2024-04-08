class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int i = 0, minLimit = INT_MIN;
        
        for (int num : preorder){
            while (i > 0 && preorder[i - 1] < num){
                minLimit = preorder[i-- - 1];
            }
            
            if (minLimit >= num) return false;
            preorder[i++] = num;
        }
        
        return true;
    }
};