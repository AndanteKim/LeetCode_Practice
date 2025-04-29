class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans, mx_elem, idx_of_mx_elems = 0, max(nums), []
        n = len(nums)

        for i in range(n):
            if nums[i] == mx_elem:
                idx_of_mx_elems.append(i)
            
            freq = len(idx_of_mx_elems)
            if freq >= k:
                ans += idx_of_mx_elems[freq - k] + 1
        
        return ans