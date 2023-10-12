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
        cache = dict()
        
        # find the index of the peak element
        low, high = 1, length - 2
        while low != high:
            mid = (low + high) >> 1
            if mid in cache:
                curr = cache[mid]
            else:
                curr = mountain_arr.get(mid)
                cache[mid] = curr
            
            if mid + 1 in cache:
                nxt = cache[mid + 1]
            else:
                nxt = mountain_arr.get(mid + 1)
                cache[mid + 1] = nxt
            
            if curr < nxt:
                if curr == target:
                    return mid
                if nxt == target:
                    return mid + 1
                low = mid + 1
            else:
                high = mid
        
        peak_index = low
        # search in the strictly increasing part of the array
        # If found, will be returned in the loop itself
        low, high = 0, peak_index
        while low <= high:
            mid = (low + high) >> 1
            if mid in cache:
                curr = cache[mid]
            else:
                curr = mountain_arr.get(mid)
            
            if curr == target:
                return mid
            elif curr < target:
                low = mid + 1
            else:
                high = mid - 1
            
        # search in the strictly decreasing part of the array
        # If found, will be returned in the loop itself
        low, high = peak_index + 1, length - 1
        
        while low <= high:
            mid = (low + high) >> 1
            if mid in cache:
                curr = cache[mid]
            else:
                curr = mountain_arr.get(mid)
            
            if curr == target:
                return mid
            elif curr > target:
                low = mid + 1
            else:
                high = mid - 1
        
        # Target is not present in the mountain array
        return -1
            