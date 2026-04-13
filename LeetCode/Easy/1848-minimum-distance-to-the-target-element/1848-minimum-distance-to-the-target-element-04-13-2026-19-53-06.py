class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        def find_idx(idx: int, ops: int) -> int:
            while 0 <= idx < n and nums[idx] != target:
                idx += ops
            return float('inf') if idx < 0 or idx >= n else idx

        n = len(nums)
        left, right = find_idx(start, -1), find_idx(start, 1)

        return min(abs(left - start), abs(right - start))