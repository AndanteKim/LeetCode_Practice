class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int blackBallCount = 0;
        
        // Iterate through each ball in the string
        for (const char& c : s){
            if (c == '0') ans += blackBallCount;
            else ++blackBallCount;
        }
        
        return ans;
    }
};