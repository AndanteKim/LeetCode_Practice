class Solution {
private:
    int dfs(int remain, int position, int rootVal){
        // Base case
        if (remain == 1) return rootVal;
        
        int totalNodes = 1 << (remain - 1);
        
        // If the position is the half side of right of tree
        if (position > (totalNodes >> 1)){
            int nextRootVal = rootVal ^ 1;
            return dfs(remain - 1, position - (totalNodes >> 1), nextRootVal);
        }
        // Left tree
        else{
            return dfs(remain - 1, position, rootVal);
        }
    }
    
    
public:
    int kthGrammar(int n, int k) {
        return dfs(n, k, 0);
    }
};