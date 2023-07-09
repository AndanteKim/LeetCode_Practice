class Solution {
public:
    int largestVariance(string s) {
        vector<int> count(26);
        
        for (char& c : s){
            ++count[c - 'a'];
        }
        
        int globalMax = 0;
        
        for (int i = 0; i < 26; ++i){
            for (int j = 0; j < 26; ++j){
                if (i == j || count[i] == 0 || count[j] == 0) continue;
                
                char major = 'a' + i, minor = 'a' + j;
                int majorCount = 0, minorCount = 0, restMinor = count[j];
                
                for (char& c : s){
                    if (c == major) ++majorCount;
                    if (c == minor) {
                        ++minorCount;
                        --restMinor;
                    }
                    if (minorCount > 0) globalMax = max(globalMax, majorCount - minorCount);
                    if (majorCount < minorCount && restMinor > 0) majorCount = 0, minorCount = 0;
                }
            }
        }
        
        return globalMax;
    }
};