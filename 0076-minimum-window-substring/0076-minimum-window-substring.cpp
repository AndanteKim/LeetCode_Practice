class Solution {
public:
    string minWindow(string s, string t) {
        struct element{
            int index;
            char charVal;
        };
        
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> dictT;
        for (char& c:t) ++dictT[c];
        int required = dictT.size(), formed = 0;
        
        vector<element> filteredS;
        for (int i = 0; i < s.size(); ++i){
            if (dictT.contains(s[i]))
                filteredS.push_back({i, s[i]});
        }
        
        int l = 0;
        int ans[3]{-1, 0, 0};
        unordered_map<char, int> windowsCount;
        for (int r = 0; r < filteredS.size(); ++r){
            char ch = filteredS[r].charVal;
            ++windowsCount[ch];
            
            if (windowsCount[ch] == dictT[ch])
                ++formed;
            
            while (l <= r && formed == required){
                ch = filteredS[l].charVal;
                int end = filteredS[r].index, start = filteredS[l].index;
                
                if (ans[0] == -1 || end - start + 1 < ans[0]){
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }
                
                --windowsCount[ch];
                if (windowsCount[ch] < dictT[ch])
                    --formed;
                ++l;
            }
        }
        return ans[0] == -1? "" : s.substr(ans[1], ans[0]);
    }
};