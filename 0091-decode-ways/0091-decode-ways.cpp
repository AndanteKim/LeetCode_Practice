class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        
        int oneBack = 1, twoBack = 1;
        
        for (int i = 1; i < s.size(); ++i){
            int curr = 0;
            if (s[i] != '0')
                curr = oneBack;
            
            int twoDigit = stoi(s.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26)
                curr += twoBack;
            twoBack = oneBack;
            oneBack = curr;
        }
        
        return oneBack;
    }
};