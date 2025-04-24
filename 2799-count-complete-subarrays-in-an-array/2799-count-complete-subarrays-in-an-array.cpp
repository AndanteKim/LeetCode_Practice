class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0, n = nums.size(), right = 0;
        unordered_set<int> distinct(nums.begin(), nums.end());
        unordered_map<int, int> cnt;
        for (int left = 0; left < n; ++left){
            if (left > 0){
                int remove = nums[left - 1];
                --cnt[remove];
                if (cnt[remove] == 0) cnt.erase(remove);
            }

            while (right < n && cnt.size() < distinct.size()){
                int add = nums[right++];
                ++cnt[add];
            }

            if (distinct.size() == cnt.size()) ans += n - right + 1;
        }

        return ans;
    }
};