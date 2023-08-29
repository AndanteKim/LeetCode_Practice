class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        // openTime penalty if the shop is kept open
        // closedTime penalty if the shop kept closed
        vector<int> openTime(n + 1), closedTime(n + 1);
        int openCnt = 0, closedCnt = 0;
        
        for (int i = 0; i < n; ++i){
            openCnt += customers[i] == 'N';
            openTime[i + 1] = openCnt;
        }
        
        for (int i = n - 1; i >= 0; --i){
            closedCnt += customers[i] == 'Y';
            closedTime[i] = closedCnt;
        }
        
        int ans = n - 1, minPenalty = INT_MAX;
        for (int i = 0; i <= n; ++i){
            if (minPenalty > openTime[i] + closedTime[i]){
                minPenalty = openTime[i] + closedTime[i];
                ans = i;
            }
        }
        
        return ans;
    }
};