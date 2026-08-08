class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        int j = m - 1;
        vector<int> last(m, -1);
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j--] = i;
            }
        }

        vector<int> ans;
        j = 0;
        int skip = 0;

        for (int i = 0; i < n; ++i) {
            
            if (j == m) break;

            if (word1[i] == word2[j] || skip == 0 && (j == m - 1 || i < last[j + 1])) {
                skip += (int)(word1[i] != word2[j++]);
                ans.push_back(i);
            }

        }

        return j == m? ans : vector<int>{};
    }
};