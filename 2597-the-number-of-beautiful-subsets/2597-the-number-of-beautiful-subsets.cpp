class Solution {
private:
    int n;
    int countBeautifulSubsets(vector<int>& nums, int diff, unordered_map<int, int>& freqMap, int i){
        // Base case: Return 1 for a subset of size 1
        if (i == n)
            return 1;
        
        // Count subsets where nums[i] isn't taken
        int totalCount = countBeautifulSubsets(nums, diff, freqMap, i + 1);
        
        // If nums[i] can be taken without violating the condition
        if (!freqMap[nums[i] - diff]){
            ++freqMap[nums[i]]; // Mark nums[i] as taken
            
            // Recursively count subsets where nums[i] is taken
            totalCount += countBeautifulSubsets(nums, diff, freqMap, i + 1);
            
            --freqMap[nums[i]]; // Backtrack: mark nums[i] as not taken
        }
            
        return totalCount;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        // Frequency map to track elements
        unordered_map<int, int> freqMap;
        this -> n = nums.size();
        // sort nums array
        sort(nums.begin(), nums.end());
        
        return countBeautifulSubsets(nums, k, freqMap, 0) - 1;
    }
};