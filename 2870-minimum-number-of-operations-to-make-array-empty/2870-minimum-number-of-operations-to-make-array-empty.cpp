class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> idxTable;
        int ans = 0;
        
        for (int num : nums)
            idxTable[num] += 1;
        
        for (auto& [num, freq] : idxTable){
            int curr = INT_MAX, max3 = freq / 3;
            
            for (int i = 0; i <= max3; ++i){
                int remain = freq - (3 * i);
                if (remain % 2 == 0)
                    curr = min(curr, i + remain / 2);
            }
            
            if (curr == INT_MAX)
                return -1;
            ans += curr;
        }
        
        return ans;
    }
};