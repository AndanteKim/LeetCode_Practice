class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long answer = 0;
        int min_pos = -1, max_pos = -1, left_bound = -1;
        
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] < minK || nums[i] > maxK) left_bound = i;
            
            if (nums[i] == minK) min_pos = i;
            if (nums[i] == maxK) max_pos = i;
            
            answer += max(0, min(min_pos, max_pos) - left_bound); 
        }
        
        return answer;
    }
};