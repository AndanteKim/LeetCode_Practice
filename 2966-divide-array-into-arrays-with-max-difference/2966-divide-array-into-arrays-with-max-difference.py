class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        n = len(nums)
        
        nums.sort()
        ans, curr = [], []
        
        for num in nums:
            if len(curr) == 3:
                if abs(curr[0] - curr[-1]) > k:
                    return []
                ans.append(curr[:])
                curr.clear()
            
            if not curr or abs(num - curr[-1]) <= k:
                curr.append(num)
            else:
                return []
        
        if len(curr) == 3 and abs(curr[0] - curr[-1]) <= k:
            ans.append(curr)
        else:
            return []
            
        return ans