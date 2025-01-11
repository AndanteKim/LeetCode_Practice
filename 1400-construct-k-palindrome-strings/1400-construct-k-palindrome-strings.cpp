class Solution {
public:
    bool canConstruct(string s, int k) {
        // Base case 1
        if (s.size() < k) return false;
        // Base case 2
        if (s.size() == k) return true;

        // Initialize oddCount as an integer bitmask
        int oddCount = 0;
        // Count the number of set bits in the bitmask
        for (const char& c : s){
            oddCount ^= 1 << (c - 'a');
        }

        // Count the number of set bits in the bitmask and
        // return if the number of odd frequencies is less than or equal to k.
        return __builtin_popcount(oddCount) <= k;
    }
};