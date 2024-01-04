class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> counter;
        for (int num : nums)
            ++counter[num];
        
        for (auto& [_, val] : counter){
            if (val == 1)
                return -1;
            ans += ceil((double) val / 3);
        }
        
        return ans;
    }
};