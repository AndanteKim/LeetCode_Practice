class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for (const string& word1 : queries) {
            int n = word1.size();
            for (const string& word2: dictionary) {
                int edits = 0;
                bool flag = true;
                for(int i = 0; i < n; ++i) {
                    if (word1[i] != word2[i]) ++edits;

                    if (edits > 2) {
                        flag = false;
                        break;
                    }
                }
                
                if (flag) {
                    ans.push_back(word1);
                    break;
                }
            }
        }

        return ans;
    }
};