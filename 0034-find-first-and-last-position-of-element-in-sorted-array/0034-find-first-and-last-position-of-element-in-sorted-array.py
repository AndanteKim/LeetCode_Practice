class Solution:
    def find_bound(self, nums: List[int], target:int, is_first: bool) -> int:
        n = len(nums)
        begin, end = 0, n - 1
        
        while begin <= end:
            mid = ((begin + end) >> 1)
            if nums[mid] == target:
                if is_first:
                    # if we find lower bound
                    if mid == begin or nums[mid - 1] < target:
                        return mid
                    # search on the left side for the bound
                    end = mid - 1
                else:
                    # if we find upper bound
                    if mid == end or nums[mid + 1] > target:
                        return mid
                    
                    # search on the right side for the bound
                    begin = mid + 1
            elif nums[mid] > target:
                end = mid - 1
            else:
                begin = mid + 1
        return -1
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = self.find_bound(nums, target, True)
        if left == -1:
            return [-1, -1]
        
        right = self.find_bound(nums, target, False)
        return [left, right]