class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        # Initialize an answer array of size n
        ans = [0] * n
        
        # Initializing two pointers to track even and 
        # odd indices for positive and negative integers respectively
        pos_idx, neg_idx = 0, 1
        
        for i in range(n):
            if nums[i] > 0:
                # Placing the positive integer at the
                # desired index in ans and incrementing pos_idx by 2
                ans[pos_idx] = nums[i]
                pos_idx += 2
            else:
                # Placing the negative integer at the
                # desired index in ans and incrementing neg_idx by 2
                ans[neg_idx] = nums[i]
                neg_idx += 2
            
        return ans