class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        string ans = "";
        unordered_map<char, vector<int>> indices;
        for (int i = 0; i < n; ++i) indices[s1[i]].push_back(i);
        vector<int> ind(m, 0);
        for (int start = 0; start <= n - 1; ++start){
            int prev = start - 1;
            for (int j = 0; j <= m - 1; ++j){
                if (!indices.count(s2[j])) return "";
                const vector<int>& curIndices = indices[s2[j]];
                while (ind[j] < curIndices.size() && curIndices[ind[j]] <= prev){
                    ++ind[j];
                }
                if (ind[j] == curIndices.size())
                    return ans;
                prev = curIndices[ind[j]];
            }
            if (ans == "" || prev - start + 1 < ans.size())
                ans = s1.substr(start, prev - start + 1);
        }
        
        return ans;
    }
};