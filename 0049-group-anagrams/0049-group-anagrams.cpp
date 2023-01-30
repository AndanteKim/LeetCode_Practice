class Solution {
private:
    string CountSort(string &s){
        int n = s.size(), counter[26] = {0};
        
        for (const char&c :s) ++counter[c - 'a'];
        
        string t;
        for (int i = 0; i < 26; ++i) t += string(counter[i], i + 'a');
        return t;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string& s: strs) groups[CountSort(s)].push_back(s);
        vector<vector<string>> ans;
        for (const auto &[key, value] : groups) ans.push_back(value);  
        return ans;
    }
};