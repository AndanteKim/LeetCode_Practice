class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans, count = float('inf'), 0
        
        for num in nums:
            if ans != num:
                if ans == float('inf') or count == 0:
                    ans = num
                    count += 1
                else:
                    count -= 1
            else:
                count += 1
            
        return ans