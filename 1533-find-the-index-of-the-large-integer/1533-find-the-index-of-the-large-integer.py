# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader(object):
#	 # Compares the sum of arr[l..r] with the sum of arr[x..y]
#	 # return 1 if sum(arr[l..r]) > sum(arr[x..y])
#	 # return 0 if sum(arr[l..r]) == sum(arr[x..y])
#	 # return -1 if sum(arr[l..r]) < sum(arr[x..y])
#    def compareSub(self, l: int, r: int, x: int, y: int) -> int:
#
#	 # Returns the length of the array
#    def length(self) -> int:
#


class Solution:
    def getIndex(self, reader: 'ArrayReader') -> int:
        left, y = 0, reader.length() - 1
        
        while left < y:
            third = (y - left) // 3
            right = left + third
            x = y - third
            
            cmp = reader.compareSub(left, right, x, y)
            
            if cmp == 0:
                left, y = right + 1, x - 1
            elif cmp == 1:
                y = right
            else:
                left = x
        
        return left
                
                