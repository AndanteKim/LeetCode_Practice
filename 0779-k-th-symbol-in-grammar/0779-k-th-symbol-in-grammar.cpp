class Solution {
private:
    int dfs(int n, int k, int rootVal){
        if (n == 1) return rootVal;
        
        // Target node will be present in the right half sub-tree of the current root node
        int totalNodes = 1 << (n - 1);
        if (k > (totalNodes / 2)){
            int nextRootVal = (rootVal == 0)? 1 : 0;
            return dfs(n - 1, k - (totalNodes / 2), nextRootVal);
        }
        // Otherwise, the target node is in the left sub-tree of the current root node
        else{
            int nextRootVal = (rootVal == 0)? 0 : 1;
            return dfs(n - 1, k, nextRootVal);
        }
    }
    
public:
    int kthGrammar(int n, int k) {
        return dfs(n, k, 0);
    }
};