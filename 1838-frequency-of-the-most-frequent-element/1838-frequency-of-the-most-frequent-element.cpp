class Solution {
private:
    int check(int i, vector<long>& prefix, vector<int>& nums, int k){
        long target = nums[i], left = 0, right = i, best = i;
        long curr = 0;
        
        while (left <= right){
            int mid = (left + right) >> 1;
            int count = i - mid + 1;
            long finalSum = count * target, originalSum = prefix[i] - prefix[mid] + nums[mid];
            long operationsRequired = finalSum - originalSum;
            if (operationsRequired > k)
                left = mid + 1;
            else{
                best = mid;
                right = mid - 1;
            }
        }
        return i - best + 1;
    }
    
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<long> prefix(nums.size());
        prefix[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
            prefix[i] = prefix[i - 1] + nums[i];
        
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
            ans = max(ans, check(i, prefix, nums, k));
        
        return ans;
    }
};