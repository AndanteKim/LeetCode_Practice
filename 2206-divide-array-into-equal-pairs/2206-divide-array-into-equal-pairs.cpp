class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int pairs = nums.size() >> 1;
        unordered_map<int, int> count;
        for (int num : nums) ++count[num];

        for (auto& [val, freq] : count){
            // If there's odd numbers, then we couldn't match a pair.
            if (freq % 2) return false;

            pairs -= (freq >> 1);
        }

        return pairs == 0;
    }
};