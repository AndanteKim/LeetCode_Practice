class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefix;
        int ans = 0, count = 0, n = nums.size();
        
        for (int i = 0; i < n; ++i){
            (nums[i] == 1)? ++count:--count;
            
            // Array from index 0 to i contains equal number of 0's and 1's
            if (count == 0) ans = max(ans, i + 1);
            
            if (prefix.find(count) != prefix.end())
                ans = max(ans, i - prefix[count]);
            else
                prefix[count] = i;
        }
        
        return ans;
    }
};