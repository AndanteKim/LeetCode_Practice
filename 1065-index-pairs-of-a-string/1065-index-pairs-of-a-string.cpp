class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        int n = text.size();
        for (string& word : words){
            for (int i = 0; i < n; ++i){
                if (word == text.substr(i, word.size())){
                    ans.push_back({i, i + (int)word.size() - 1});
                }
            }
        }
        
        sort(ans.begin(), ans.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[1] < b[1];
            else return a[0] < b[0];
        });
        
        return ans;
    }
};