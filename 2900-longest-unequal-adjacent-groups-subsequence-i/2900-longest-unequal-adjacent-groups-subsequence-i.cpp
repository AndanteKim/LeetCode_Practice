class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(), curr = -1;
        vector<string> ans;
        for (int i = 0; i < n; ++i){
            if (curr == -1 || curr != groups[i]){
                curr = groups[i];
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};