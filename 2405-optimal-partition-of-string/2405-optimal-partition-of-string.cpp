class Solution {
public:
    int partitionString(string s) {
        int ans = 1, substrStart = 0;
        vector<int> lastSeen(26, -1);
        
        for (int i = 0; i < s.size(); ++i){
            if (lastSeen[s[i] - 'a'] >= substrStart){
                ++ans;
                substrStart = i;
            }
            lastSeen[s[i] - 'a'] = i;
        }
        
        return ans;
    }
};