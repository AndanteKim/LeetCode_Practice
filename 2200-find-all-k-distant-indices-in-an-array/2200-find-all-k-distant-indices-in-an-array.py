class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans, key_indices = [], []

        for i, num in enumerate(nums):
            if num == key:
                key_indices.append(i)

        for i, num in enumerate(nums):
            for j in key_indices:
                if abs(i - j) <= k:
                    ans.append(i)
                    break

        return ans