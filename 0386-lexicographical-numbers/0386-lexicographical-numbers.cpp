class Solution {
private:
    int n;
    void backtrack(vector<int>& ans, int digit){
        // Base case
        if (digit > n) return;
        
        ans.push_back(digit);
        digit *= 10;
        
        for (int i = 0; i <= 9; ++i)
            backtrack(ans, digit + i);
    }
    
public:
    vector<int> lexicalOrder(int n) {
        this -> n = n;
        vector<int> ans;
        for (int i = 1; i <= 9; ++i)
            backtrack(ans, i);
        
        return ans;
    }
};