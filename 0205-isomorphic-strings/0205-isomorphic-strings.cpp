class Solution {
    string transformString(string s){
        unordered_map<char, int> index_mapping;
        string decode = "";
        for (int i = 0; i < s.size(); ++i){
            if (index_mapping.find(s[i]) == index_mapping.end()) index_mapping[s[i]] = i;
            decode += (char) (index_mapping[s[i]]);
        }
        
        return decode;
    }
    
public:
    bool isIsomorphic(string s, string t) {
        return transformString(s) == transformString(t);
    }
};