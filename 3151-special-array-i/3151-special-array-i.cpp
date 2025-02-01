class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // Iterate through the indices 0 to n - 1
        for (int i = 0; i < nums.size() - 1; ++i){
            // Compare the parities of the current and next number
            if (nums[i] % 2 == nums[i + 1] % 2)
                // If the two adjacent numbers have the same parity, return false
                return false;
        }

        // Return true if no pair of adjacent numbers with the same parity are found.
        return true;
    }
};