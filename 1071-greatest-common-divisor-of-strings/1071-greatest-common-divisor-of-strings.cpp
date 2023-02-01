class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<string> prefix_candidates;
        for (int i = 1; i <= n; ++i){
            string prefix = str2.substr(0, i);
            
            string s1 = prefix, s2 = prefix;
            for (int j = 1; j < m / i; ++j) s1 += prefix;
            for (int j = 1; j < n / i; ++j) s2 += prefix;
            
            if (s1 == str1 && s2 == str2) prefix_candidates.push_back(prefix);
        }
        
        return prefix_candidates.empty()? "" : prefix_candidates.back();
    }
};