class Solution {
public:
    int countHomogenous(string s) {
        int currStreak = 0, ans = 0, MOD = 1'000'000'007;
        
        for (int i = 0; i < s.size(); ++i){
            if (i == 0 || s[i] == s[i - 1])
                ++currStreak;
            else
                currStreak = 1;
            ans = (ans + currStreak) % MOD;
        }
        
        return ans;
    }
};