class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int lowest = INT_MAX, start = INT_MIN;
        vector<int> counting(5 * 1e4 + 1);
        
        for (int num : nums){
            ++counting[num];
            lowest = min(lowest, num);
            start = max(start, num);
        }
        
        int ans = 0, curr = start - 1, prev = start;
        while (counting[lowest] < nums.size()){
            if (counting[curr] > 0){
                ans += counting[prev];
                counting[curr] += counting[prev];
                prev = curr;
            }
            --curr;
        }
        
        return ans;
    }
};