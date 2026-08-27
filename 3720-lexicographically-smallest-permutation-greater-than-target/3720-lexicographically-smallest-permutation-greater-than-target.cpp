class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26);
        for (const char& c : s) ++cnt[c - 'a'];

        string ans;
        int n = target.size();
        for (int i = 0; i < n; ++i){
            int targetCh = target[i] - 'a';

            if (cnt[targetCh] > 0) {
                --cnt[targetCh];
                if (canGreater(cnt, target, i + 1)) {
                    ans.push_back(target[i]);
                    continue;
                }

                ++cnt[targetCh];
            }

            for (int j = targetCh + 1; j < 26; ++j) {
                if (cnt[j] > 0) {
                    --cnt[j];
                    ans.push_back('a' + j);

                    ans += getMinStr(cnt);
                    return ans;
                }
            }

            return "";
        }

        return "";
    }

private:
    bool canGreater(const vector<int>& cnt, const string& target, int start) {
        string maxStr = getMaxStr(cnt);
        string suffix = target.substr(start);
        return maxStr > suffix;
    }

    string getMaxStr(const vector<int>& cnt) {
        string res;
        for (int i = 25; i >= 0; --i) {
            res.append(cnt[i], 'a' + i);
        }

        return res;
    }

    string getMinStr(const vector<int>& cnt) {
        string res;
        for (int i = 0; i < 26; ++i) res.append(cnt[i], 'a' + i);
    
        return res;
    }
};