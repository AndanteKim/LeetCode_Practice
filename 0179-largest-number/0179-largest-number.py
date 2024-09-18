class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Convert numbers to strings for concatenation
        num_strs = list(map(str, nums))
        
        # Custom comparator: Compare which combination of two strings gives a larger number
        def compare(x: str, y: str) -> int:
            if x + y > y + x:
                return -1   # x should come before y
            elif x + y < y + x:
                return 1    # y should come before x
            else:
                return 0    # They are equal in terms of ordering
            
        # Sort the list using the custom comparator
        num_strs.sort(key = cmp_to_key(compare))
        
        # Join the sorted strings into the largest number
        ans = "".join(num_strs)
        
        # Edge case: If the largest number starts with '0', return '0'
        return "0" if ans[0] == '0' else ans
            