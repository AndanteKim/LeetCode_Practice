class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        length, idx_dq = len(nums), deque()
        ans = [-1] * (length - k + 1)
        
        for idx in range(length):
            if idx_dq and idx_dq[0] < idx - k + 1:
                idx_dq.popleft()
                
            if idx_dq and nums[idx] != nums[idx - 1] + 1:
                idx_dq.clear()
                
            idx_dq.append(idx)
            
            if idx >= k - 1:
                if len(idx_dq) == k:
                    ans[idx - k + 1] = nums[idx_dq[-1]]
                else:
                    ans[idx - k + 1] = -1
                    
        return ans