class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Set to store all prefixes from arr1
        unordered_set<int> arr1Prefix;
        
        // Step1: Build all possible prefixes from arr1
        for (int val : arr1){
            while (val > 0 && !arr1Prefix.count(val)){
                // Insert current value as a prefix
                arr1Prefix.insert(val);
                // Generate the next shorter prefix by removing the last digit
                val /= 10;
            }
        }
        
        int longestPrefix = 0;
        // Step2: Check each number in arr2 for the longest matching prefix
        for (int val : arr2){
            while (val > 0 && !arr1Prefix.count(val))
                // Reduce val by removing the last digit if not found in the
                // prefix set
                val /= 10;
            
            if (val > 0)
                // Length of the matched prefix using log10 to determine the 
                // number of digits
                longestPrefix = max(longestPrefix, static_cast<int>(log10(val) + 1));
        }
        
        return longestPrefix;
    }
};