class Solution {
private:
    int n, k;

    void addMode(int value, vector<int>& nums, set<int>& modes){
        if (value - k >= nums[0]) modes.insert(value - k);
        if (value + k <= nums.back()) modes.insert(value + k);
        modes.insert(value);
    }

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        this -> n = nums.size();
        this -> k = k;

        sort(nums.begin(), nums.end());
        set<int> modes;
        unordered_map<int, int> freqs;
        int ans = 0, lastNumIndex = 0;
        for (int i = 0; i < n; ++i){
            if (nums[i] != nums[lastNumIndex]){
                addMode(nums[lastNumIndex], nums, modes);
                ans = max(ans, i - lastNumIndex);
                lastNumIndex = i;
            }
            ++freqs[nums[i]];
        }
        
        addMode(nums[lastNumIndex], nums, modes);
        ans = max(ans, n - lastNumIndex);

        int curr, left, right;
        for (int mode : modes){
            left = lower_bound(nums.begin(), nums.end(), mode - k) - nums.begin();
            right = upper_bound(nums.begin(), nums.end(), mode + k) - nums.begin();

            curr = min(right - left, freqs[mode] + numOperations);
            ans = max(ans, curr);
        }

        return ans;
    }
};