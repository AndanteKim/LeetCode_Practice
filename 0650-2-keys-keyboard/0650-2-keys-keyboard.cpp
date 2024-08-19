class Solution {
private:
    int n;
    
    int minStepsHelper(int currLen, int pasteLen, vector<vector<int>>& memo){
        if (currLen == n)
            return 0;
        
        if (currLen > n)
            return 1000;
        
        // return the result if it has been already calculated
        if (memo[currLen][pasteLen] != -1)
            return memo[currLen][pasteLen];
        
        int opt1 = 1 + minStepsHelper(currLen + pasteLen, pasteLen, memo);
        int opt2 = 2 + minStepsHelper(currLen * 2, currLen, memo);
        return memo[currLen][pasteLen] = min(opt1, opt2);
    }
    
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        this -> n = n;
        vector<vector<int>> memo(n + 1, vector<int>((n >> 1) + 1, -1));
        
        return 1 + minStepsHelper(1, 1, memo);
    }
};