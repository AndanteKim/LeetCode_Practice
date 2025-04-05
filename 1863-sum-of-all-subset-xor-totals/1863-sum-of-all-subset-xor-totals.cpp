class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;

        // Capture each bit that is set in any of the elements
        for (int num : nums){
            ans |= num;
        }

        // Multiply by the number of subset XOR totals that will have each bit set
        return ans << ((int)nums.size() - 1);
    }
};