class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        ans, pos, neg, n = [], [], [], len(nums)
        
        for i in range(n):
            if nums[i] > 0:
                pos.append(i)
            else:
                neg.append(i)
        
        idx = 0
        while idx < max(len(pos), len(neg)):
            if idx < len(pos):
                ans.append(nums[pos[idx]])
            
            if idx < len(neg):
                ans.append(nums[neg[idx]])
            
            idx += 1
            
        return ans