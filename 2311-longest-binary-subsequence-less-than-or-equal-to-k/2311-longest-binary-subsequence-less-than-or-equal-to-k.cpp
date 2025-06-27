class Solution {
public:
    int longestSubsequence(string s, int k) {
        int total = 0, cnt = 0;
        int bits = 32 - __builtin_clz(k);
        
        for (int i = 0; i < s.size(); ++i){
            char ch = s[s.size() - 1 - i];

            if (ch == '1'){
                if (i < bits && total + (1 << i) <= k){
                    total += 1 << i;
                    ++cnt;
                }
            }
            else ++cnt;
        }

        return cnt;
    }
};