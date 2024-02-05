class Solution {
public:
    int firstUniqChar(string s) {
        map<char, vector<int>> dict;
        int ans = -1;
        
        for (int i = 0; i < s.size(); ++i)
            dict[s[i]].push_back(i);
        
        for (auto& [_, val]:dict){
            if (val.size() == 1)
                ans = (ans == -1)? val[0]:min(ans,val[0]);
        }
        
        return ans;
    }
};