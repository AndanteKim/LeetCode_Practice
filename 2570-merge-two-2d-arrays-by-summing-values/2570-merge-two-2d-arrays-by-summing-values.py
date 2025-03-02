class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        def count_nums(nums: List[List[int]]) -> int:
            cnt = 0
            for id, val in nums:
                cnt = max(cnt, id)
            return cnt + 1
        
        def allocation(rows: List[int], nums: List[List[int]]) -> None:
            for id, val in nums:
                rows[id] += val
        
        count = count_nums(nums1)
        count = max(count, count_nums(nums2))

        rows = [0] * (count + 1)

        allocation(rows, nums1)
        allocation(rows, nums2)
        ans = []

        for i, val in enumerate(rows):
            if val > 0:
                ans.append([i, val])

        return ans