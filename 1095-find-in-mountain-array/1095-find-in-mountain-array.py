# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        length = mountain_arr.length()
        
        # find the index of the peak element
        low, high = 1, length - 2
        while low < high:
            mid = (low + high) >> 1
            if mountain_arr.get(mid) < mountain_arr.get(mid + 1):
                low = mid + 1
            else:
                high = mid
        peak_index = low
        
        # search in the strictly increasing part of the array
        low, high = 0, peak_index
        while low < high:
            mid = (low + high) >> 1
            if mountain_arr.get(mid) < target:
                low = mid + 1
            else:
                high = mid
        
        # check if the target is present in the strictly increasing part
        if mountain_arr.get(low) == target:
            return low
        
        # otherwise, search in the strictly decreasing part
        low, high = peak_index + 1, length - 1
        while low < high:
            mid = (low + high) >> 1
            if mountain_arr.get(mid) > target:
                low = mid + 1
            else:
                high = mid
        
        # check if the target is present in the strictly decreasing part
        if mountain_arr.get(low) == target:
            return low
        
        # no target in the mountain array
        return -1
        