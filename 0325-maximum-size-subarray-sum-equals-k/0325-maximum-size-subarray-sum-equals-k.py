class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        psum = max_len = 0
        indices = {0: -1}

        for i, num in enumerate(nums):
            psum += num

            if psum - k in indices:
                max_len = max(max_len, i - indices[psum - k])
            
            if psum not in indices:
                indices[psum] = i

        return max_len