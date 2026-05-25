class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n), prefix(n);
        dp[0] = 1;

        for (int i = 0; i < minJump; ++i) prefix[i] = 1;

        for (int i = minJump; i < n; ++i) {
            int left = i - maxJump, right = i - minJump;

            if (s[i] == '0'){
                int total = prefix[right] - (left <= 0? 0: prefix[left - 1]);
                dp[i] = int(total != 0);
            }

            prefix[i] = prefix[i - 1] + dp[i];
        }

        return (bool)dp.back();
    }
};