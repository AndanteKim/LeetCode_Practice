class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        ans = nums[0]
        
        for i in range(len(nums) - 1): 
            if (nums[i + 1] - nums[i] - 1) < k:
                k -= (nums[i + 1] - nums[i] - 1)
                ans = nums[i + 1]
            else:
                while k > 0:
                    ans += 1
                    k -= 1
                break
        
        return ans if k == 0 else ans + k
            
             
                
        
            