class Solution {
private:
    int n;

    bool isValid(vector<int>& nums, int curr, int dir, int remain){
        vector<int> temp(nums.begin(), nums.end());

        while (remain > 0 && 0 <= curr && curr < n){
            if (temp[curr] > 0){
                --temp[curr];

                if (temp[curr] == 0)
                    --remain;
                
                dir *= -1;
            }
            curr += dir;
        }

        return remain == 0;
    }

public:
    int countValidSelections(vector<int>& nums) {
        this -> n = nums.size();
        int ans = 0, nonZeroes = 0;
        for (int num : nums) if (num > 0) ++nonZeroes;

        for (int i = 0; i < n; ++i){
            if (nums[i] == 0){
                ans += isValid(nums, i, -1, nonZeroes);
                ans += isValid(nums, i, 1, nonZeroes);
            }
        }

        return ans;
    }
};