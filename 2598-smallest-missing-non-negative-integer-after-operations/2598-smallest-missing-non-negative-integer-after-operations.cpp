class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> modFreq;
        int maxNum = 1'000'000'000, adjust;

        for (int num : nums) {
            if (num < 0){
                adjust = (value + (num % value));
                ++modFreq[adjust % value];
            }
            else
                ++modFreq[num % value];
        }

        int target, missing = 0;
        while (true){
            target = missing % value;
            if (modFreq[target] == 0) return missing;
            ++missing;
            --modFreq[target];
        }

        return -1;
    }
};