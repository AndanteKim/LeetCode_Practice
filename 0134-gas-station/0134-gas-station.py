class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, currGain = 0, totalGain = 0, n = gas.size();
        
        for (int i = 0; i < n; ++i){
            totalGain += gas[i] - cost[i];
            currGain += gas[i] - cost[i];
            
            if (currGain < 0){
                currGain = 0;
                ans = i + 1;
            }
        }
        
        return totalGain < 0? -1:ans;
    }
};