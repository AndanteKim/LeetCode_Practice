class Solution {
private:
    bool checkBalance(unordered_map<char, int>& cnt) {
        for (const auto& [_, freq] : cnt) {
            if (freq != 0) return true;
        }

        return false;
    }

public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> evenCnt, oddCnt;
        int n = s1.size();

        for (int i = 0; i < n; ++i) {
            if (i % 2) {
                ++oddCnt[s1[i]];
                --oddCnt[s2[i]];
            }
            else {
                ++evenCnt[s1[i]];
                --evenCnt[s2[i]];
            }
        }

        if (checkBalance(oddCnt) || checkBalance(evenCnt)) return false;
        return true;
    }
};