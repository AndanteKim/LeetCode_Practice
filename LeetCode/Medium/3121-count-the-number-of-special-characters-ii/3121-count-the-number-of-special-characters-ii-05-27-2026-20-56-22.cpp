class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerCases(26, -1), upperCases(26, -1);

        for (int i = 0; i < word.size(); ++i) {
            if (word[i] >= 97) {
                int idx = word[i] - 97;
                lowerCases[idx] = i;
            }
            else {
                int idx = word[i] - 65;
                if (upperCases[idx] == -1) upperCases[idx] = i;
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (lowerCases[i] != -1 && upperCases[i] != -1 && lowerCases[i] < upperCases[i]) ++ans;
        }

        return ans;
    }
};