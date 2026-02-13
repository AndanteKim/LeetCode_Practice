class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1, n = s.size();

        for (int i = 0; i < n; ++i) {
            vector<int> freqs(26);

            for (int j = i; j < n; ++j) {
                ++freqs[s[j] - 97];
                bool flag = true;
                for (int k = 0; k < 26; ++k){
                    if (freqs[k] != 0 && freqs[k] != freqs[s[j] - 97]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) ans = max(ans, j - i + 1);
            
            }
        }

        return ans;
    }
};