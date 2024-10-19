class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or_val, n = 0, len(nums)
        
        for num in nums:
            max_or_val |= num
            
        # 2^n subsets
        total_subsets, subsets_with_max_or = 1 << n, 0
        
        # Iterate through all possible subsets
        for subset_mask in range(total_subsets):
            curr_or_val = 0
            
            # Calculate OR value for the current subset
            for i in range(n):
                if (subset_mask >> i) & 1:
                    curr_or_val |= nums[i]
                    
            # If current subset's OR equals max_or_val, increment count
            if curr_or_val == max_or_val:
                subsets_with_max_or += 1
                
        return subsets_with_max_or