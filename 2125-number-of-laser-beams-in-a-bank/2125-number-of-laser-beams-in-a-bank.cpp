class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> rowConstitute;
        int ans = 0;
        
        for (string& row:bank){
            int numCamera = count(row.begin(), row.end(), '1');
            if (numCamera)
                rowConstitute.push_back(numCamera);
        }
        
        for (int i = 1; i < rowConstitute.size(); ++i)
            ans += rowConstitute[i - 1] * rowConstitute[i];
        
        return ans;
    }
};