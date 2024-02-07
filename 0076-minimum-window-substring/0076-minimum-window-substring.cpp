class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";
        
        unordered_map<char, int> dictT, windowCounts;
        for (const char& c:t)
            ++dictT[c];
        
        int required = dictT.size(), formed = 0, left = 0;
        vector<pair<int, char>> filteredS;
        
        for (int i = 0; i < s.size(); ++i)
            if (dictT.count(s[i]))
                filteredS.push_back(make_pair(i, s[i]));
        
        int ans[3];
        ans[0] = INT_MAX;
        // Look for the characters only in the filtered list instead of entire s. This helps to reduce our search.
        // Hence, we follow the sliding window approach on as small list.
        for (int right = 0; right < filteredS.size(); ++right){
            char ch = filteredS[right].second;
            ++windowCounts[ch];
            
            if (windowCounts[ch] == dictT[ch]) ++formed;
            
            // If the current window has all the characters in desired frequencies i.e. t is present in the window.
            while (left <= right && formed == required){
                ch = filteredS[left].second;
                
                // save the smallest window until now.
                int end = filteredS[right].first, start = filteredS[left].first;
                if (end - start + 1 < ans[0]){
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }
                --windowCounts[ch];
                if (windowCounts[ch] < dictT[ch])
                    --formed;
                ++left;
            }
        }
        
        return ans[0] == INT_MAX? "":s.substr(ans[1], ans[2]-ans[1] + 1);
    }
};