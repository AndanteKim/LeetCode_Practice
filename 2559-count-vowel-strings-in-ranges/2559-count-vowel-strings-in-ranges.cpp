class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixVowels(words.size() + 1, 0), ans(queries.size(), 0);
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < words.size(); ++i){
            if (!(vowels.count(words[i][0]) && vowels.count(words[i].back())))
                prefixVowels[i + 1] = prefixVowels[i];
            else
                prefixVowels[i + 1] = prefixVowels[i] + 1;
        }

        for (int i = 0; i < queries.size(); ++i){
            int left = queries[i][0], right = queries[i][1];
            ans[i] = prefixVowels[right + 1] - prefixVowels[left];
        }

        return ans;
    }
};