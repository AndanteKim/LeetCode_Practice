class Solution {
public:
    int minOperations(string s) {
        vector<char> pattern{'1','0'};
        int changesOZ = 0, changesZO = 0;
        
        for (int i = 0; i < s.size(); ++i){
            if (pattern[i % 2] == s[i])
                ++changesOZ;
            else
                ++changesZO;
        }
        return min(changesOZ, changesZO);
    }
};