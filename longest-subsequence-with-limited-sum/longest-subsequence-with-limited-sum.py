class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        for i in range(1, len(nums)):
            nums[i] = nums[i] + nums[i - 1]
        
        ans = [0] * len(queries)
        for i in range(len(queries)):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == queries[i]:
                    ans[i] = mid + 1
                    break
                if nums[mid] > queries[i]:
                    right = mid - 1
                else:
                    left = mid + 1
            if ans[i] == 0:
                ans[i] = left
        return ans