class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n, ans = len(nums), float('inf')
        bits, left, curr = [0] * 32, 0, 0

        for right in range(n):
            num, mask_idx = nums[right], 0
            
            while num >= (1 << mask_idx):
                bits[mask_idx] += num & (1 << mask_idx)
                curr |= (num & (1 << mask_idx))
                mask_idx += 1
            
            while left <= right and curr >= k:
                ans, num, mask_idx = min(ans, right - left + 1), nums[left], 0
                while num >= (1 << mask_idx):
                    bits[mask_idx] -= (num & (1 << mask_idx))
                    if (num & (1 << mask_idx)) and bits[mask_idx] == 0:
                        curr ^= (1 << mask_idx)
                    mask_idx += 1
                left += 1
                    
        return -1 if ans == float('inf') else ans