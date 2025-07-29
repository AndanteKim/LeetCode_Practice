class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size(), j;
        vector<int> ans(n);
        vector<int> pos(31, -1);

        for (int i = n - 1; i >= 0; --i){
            j = i;

            for (int bit = 0; bit < 31; ++bit){
                if ((nums[i] & (1 << bit)) == 0){
                    if (pos[bit] != -1) j = max(j, pos[bit]);
                }
                else
                    pos[bit] = i;
            }

            ans[i] = j - i + 1;
        }

        return ans;
    }
};