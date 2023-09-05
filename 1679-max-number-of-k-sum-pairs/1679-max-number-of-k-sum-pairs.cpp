class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        int ans = 0;
        
        for (int num : nums){
            int complement = k - num;
            if (lookup[complement] > 0) {
                --lookup[complement];
                ++ans;
            }
            else ++lookup[num];
        }
        
        return ans;
    }
};