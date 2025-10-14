class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        def is_increasing(arr: List[int]) -> bool:
            for i in range(k - 1):
                if arr[i] >= arr[i + 1]:
                    return False
            
            return True
        
        n = len(nums)

        for i in range(n - 2 * k):
            a = nums[i : i + k]
            a_inc = is_increasing(a)

            b = nums[i + k : i + 2 * k]
            b_inc = is_increasing(b)
            
            if a_inc and b_inc:
                return True

        return False