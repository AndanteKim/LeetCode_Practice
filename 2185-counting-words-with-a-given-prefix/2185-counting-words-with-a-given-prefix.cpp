class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int p = pref.size(), ans = 0;

        for (const string& word : words){
            if (p > word.size())
                continue;

            int j = 0;
            for (int i = 0; i < p; ++i)
                if (pref[i] == word[i])
                    ++j;
            if (j == p)
                ++ans;
        }

        return ans;
    }
};