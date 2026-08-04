class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> buckets(101);
        int mn = std::numeric_limits<int>::max(), mx = std::numeric_limits<int>::min();
        
        for (int num : nums) {
            ++buckets[num];
            mn = min(mn, num);
            mx = max(mx, num);
        }

        vector<int> ans;

        for (int i = mn; i <= mx; ++i) {
            if (!buckets[i]) ans.push_back(i);
        }

        return ans;
    }
};