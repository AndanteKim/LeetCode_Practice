class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        for (int mask = 0; mask < (1 << requests.size()); ++mask){
            vector<int> indegree(n, 0);
            int pos = requests.size() - 1;
            int bitCount = __builtin_popcount(mask);
            
            if (bitCount <= ans)
                continue;
            
            for (int curr = mask; curr > 0 ; curr >>= 1, --pos){
                if (curr & 1){
                    --indegree[requests[pos][0]];
                    ++indegree[requests[pos][1]];
                }
            }
            
            int flag = 1;
            for (int i = 0; i < n; ++i){
                if (indegree[i]){
                    flag = 0;
                    break;
                }
            }
            
            if (flag) ans = bitCount;
        }
        
        return ans;
    }
};