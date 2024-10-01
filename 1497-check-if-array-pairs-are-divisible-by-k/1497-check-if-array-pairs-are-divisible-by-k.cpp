class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        // Store the count of remainders in a map.
        unordered_map<int, int> freq;
        for (int num : arr){
            int target = (k + (num % k)) % k;
            ++freq[target];
        }
        
        for (int num : arr){
            int target = (k + (num % k)) % k;

            // If the remainder for an element is 0, then the count of
            // numbers that give this remainder must be even.
            if (target == 0){
                if (freq[target] % 2) return false;
            }
            // If the remainder target and k - target don't have the same
            // count then pairs cannot be made.
            else if (freq[target] != freq[k - target])
                return false;
        }
        
        return true;
    }
};