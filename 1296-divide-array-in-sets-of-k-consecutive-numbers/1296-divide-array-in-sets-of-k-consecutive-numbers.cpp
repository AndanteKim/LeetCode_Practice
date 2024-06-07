class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        
        // Count to store the count of each frequency
        unordered_map<int, int> count;
        for (int n:nums) ++count[n];
        
        for (int num:nums){
            int start = num;
            
            // Find the start of the potential straight sequence
            while (count[start - 1] != 0) --start;
            
            // Process the sequence starting from start
            while (start <= num){
                while (count[start] != 0){
                    // Check if we can form a consecutive sequence of k
                    for (int next = start; next < start + k; ++next){
                        if (count[next] == 0) return false;
                        --count[next];
                    }
                }
                ++start;
            }
        }
        
        return true;
    }
};