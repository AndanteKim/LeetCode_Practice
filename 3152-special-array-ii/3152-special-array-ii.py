class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        def binary_search(start: int, end: int, violating_indices: List[int]) -> bool:
            left, right = 0, len(violating_indices) - 1
            
            while left <= right:
                mid = left + ((right - left) >> 1)
                violating_idx = violating_indices[mid]
                
                if violating_idx < start:
                    # Check right half
                    left = mid + 1
                elif violating_idx > end:
                    # Check left half
                    right = mid - 1
                else:
                    # violating_idx falls in between start and end
                    return True
                
            return False
        
        
        n, q = len(nums), len(queries)
        ans, violating_indices = [False] * q, []
        
        for i in range(1, n):
            # same parity, found violating index
            if nums[i] % 2 == nums[i - 1] % 2:
                violating_indices.append(i)
                
        for i in range(q):
            start, end = queries[i]
            found_violating_idx = binary_search(start + 1, end, violating_indices)
            
            if found_violating_idx:
                ans[i] = False
            else:
                ans[i] = True
        
        return ans