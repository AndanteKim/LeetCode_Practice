class Solution {
private:
    void backtrack(int digit, int num, int k, vector<int>& ans){
        if (digit == 0){
            ans.push_back(num);
            return;
        }
        
        int tailDigit = num % 10; 
        unordered_set<int> nextDigits{{tailDigit + k, tailDigit - k}};
        for (int nextDigit: nextDigits){
            if (0 <= nextDigit && nextDigit < 10){
                int newNum = num * 10 + nextDigit;
                backtrack(digit - 1, newNum, k, ans);
            }
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if (n == 1) return {1,2,3,4,5,6,7,8,9};
        vector<int> ans;
        for (int num = 1; num < 10; ++num) backtrack(n - 1, num, k, ans);
        return ans;
    }
};