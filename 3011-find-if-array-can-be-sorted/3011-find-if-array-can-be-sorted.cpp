class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        // Number of set bits of the elements in the current segment
        int n = nums.size();
        int maxOfSegment = nums[0], minOfSegment = nums[0];
        int numOfSetBits = __builtin_popcount(nums[0]);
        
        // Initialize max of the previous segment to the smallest possible integer
        int maxOfPrevSegment = std::numeric_limits<int>::min();
        
        for (int i = 1; i < n; ++i){
            if (numOfSetBits == __builtin_popcount(nums[i])){
                // Element belongs to the same segment
                // Update min and max values of the segment
                maxOfSegment = max(maxOfSegment, nums[i]);
                minOfSegment = min(minOfSegment, nums[i]);
            }
            else{   // Element belongs to a new segment
                // Check if the segments are arranged properly
                if (minOfSegment < maxOfPrevSegment)
                    return false;
                
                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;
                
                // Start a new segment with the current element
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        
        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment) return false;
        
        return true;
    }
};