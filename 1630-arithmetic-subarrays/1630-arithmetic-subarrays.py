class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        def check(arr: List[int]) -> bool:
            min_element, max_element = min(arr), max(arr)
            if (max_element - min_element) % (len(arr) - 1) != 0:
                return False
            
            diff = (max_element - min_element) // (len(arr) - 1)
            arr_set = set(arr)
            curr = min_element + diff
            while curr < max_element:
                if curr not in arr_set:
                    return False
                curr += diff
            
            return True
            
        ans = []
        for i in range(len(l)):
            arr = nums[l[i] : r[i] + 1]
            ans.append(check(arr))
        return ans