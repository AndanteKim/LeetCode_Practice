class Solution {
public:
    int partitionString(string s) {
        vector<int> hash_table(26, 0);
        int ans = 1;
        for(const char& c: s){
            if (hash_table[c - 'a'] == 0)
                ++hash_table[c - 'a'];
            else {
                ++ans;
                for (int i = 0; i < 26; ++i) hash_table[i] = 0;
                ++hash_table[c - 'a'];
            }
        }
        
        return ans;
    }
};