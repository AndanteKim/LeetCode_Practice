class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (const string& word : words) {
            int curr = 0;
            for (const char& c : word) {
                curr += weights[c - 'a'];
            }
            ans.push_back((char)('z' - curr % 26));
        }

        return ans;
    }
};