class Solution {
private:
    int n;
    int recursiveWithMemo(int i, string& s, vector<int>& memo){
        if (i >= n){
            return (i == n)? 1:0;
        }
        
        if (s[i] == '0')
            return 0;
        
        if (i == n - 1)
            return 1;
        
        if (memo[i] != -1)
            return memo[i];
        
        int ans = recursiveWithMemo(i + 1, s, memo);
        if (stoi(s.substr(i, 2)) <= 26)
            ans += recursiveWithMemo(i + 2, s, memo);
        return memo[i] = ans;
    }
    
public:
    int numDecodings(string s) {
        this -> n = s.size();
        vector<int> memo(n, -1);
        return recursiveWithMemo(0, s, memo);
    }
};