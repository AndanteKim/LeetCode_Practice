class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size(), currOne = 0, left = 0, deleted = 0;

        for (int right = 0; right < n; ++right){
            while (left < right && deleted > 1){
                if (nums[left++] == 0) --deleted;
                else --currOne;;
            }

            if (nums[right] == 0) ++deleted;
            else ++currOne;

            ans = max(ans, currOne);
        }

        if (ans > 0 && deleted == 0) --ans;

        return ans;
    }
};