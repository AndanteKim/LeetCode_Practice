class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int alphabetSize = 26;
        vector count(alphabetSize, vector<int>(alphabetSize, 0));

        for (const string& word : words){
            ++count[word[0] - 97][word[1] - 97];
        }

        int ans = 0;
        bool central = false;
        for (int i = 0; i < 26; ++i){
            if (count[i][i] % 2 == 0)
                ans += count[i][i];
            else{
                ans += count[i][i] - 1;
                central = true;
            }

            for (int j = i + 1; j < 26; ++j)
                ans += 2 * min(count[i][j], count[j][i]);
        }

        if (central) ++ans;

        return 2 * ans;
    }
};