class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        vector<int> substr(26, 0);
        
        for (char& c: s){
            if (substr[c - 'a'] == 0)
                ++substr[c - 'a'];
            else{
                for (int i = 0; i < 26; ++i) substr[i] = 0;
                ++substr[c - 'a'];
                ++ans;
            }
        }
        
        return ans;
    }
};