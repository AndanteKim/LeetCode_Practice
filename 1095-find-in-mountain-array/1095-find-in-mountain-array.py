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
        
        low, high = 1, length - 2
        while low != high:
            mid = (low + high) >> 1
            curr = mountain_arr.get(mid)
            nxt = mountain_arr.get(mid + 1)
            
            if curr < nxt:
                if curr == target:
                    return mid
                if nxt == target:
                    return mid + 1
                low = mid + 1
            else:
                high = mid
        
        peak_index = low
        
        low, high = 0, peak_index
        while low <= high:
            mid = (low + high) >> 1
            curr = mountain_arr.get(mid)
            
            if curr == target:
                return mid
            if curr < target:
                low = mid + 1
            else:
                high = mid - 1
        
        low, high = peak_index + 1, length - 1
        while low <= high:
            mid = (low + high) >> 1
            curr = mountain_arr.get(mid)
            
            if curr == target:
                return mid
            elif curr > target:
                low = mid + 1
            else:
                high = mid - 1
        
        return -1