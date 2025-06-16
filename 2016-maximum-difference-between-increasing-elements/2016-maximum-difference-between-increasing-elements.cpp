class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, n = nums.size();
        vector<int> increasing;

        for (int num : nums){
            while (!increasing.empty() && increasing.back() > num) increasing.pop_back();
            if (!increasing.empty() && increasing[0] < num) ans = max(ans, num - increasing[0]);
            increasing.push_back(num);
        }
        
        return ans;
    }
};