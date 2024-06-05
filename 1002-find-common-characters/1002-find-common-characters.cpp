class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26);
        vector<string> ans;
        
        for (int i1 = 0; i1 < words.size(); ++i1){
            vector<int> chars(26);
            for (char& c : words[i1])
                ++chars[c - 'a'];
            
            if (i1 > 0)
                for (int i2 = 0; i2 < 26; ++i2)
                    common[i2] = min(common[i2], chars[i2]);
            else
                common = chars;
        }
        
        for (int i = 0; i < 26; ++i)
            for (int _ = 0; _ < common[i]; ++_)
                ans.push_back(string(1, (char)(97 + i)));
        
        return ans;
    }
};