class Solution {
public:
    int concatenatedBinary(int n) {
        int ans = 0, MOD = pow(10, 9) + 7;

        for (int i = 1; i <= n; ++i) {
            int temp = i;
            string curr = "";
            while (temp > 0) {
                curr.push_back(char(temp % 2 + 48));
                temp >>= 1;
            }
            reverse(curr.begin(), curr.end());
            ans = ((long long)ans << curr.size()) % MOD;
            ans = ((long long)ans + i) % MOD;
        }

        return ans;
    }
};