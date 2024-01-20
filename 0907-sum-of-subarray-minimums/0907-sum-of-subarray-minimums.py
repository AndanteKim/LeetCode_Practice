class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 1_000_000_007
        stack, ans = [], 0
        
        for i in range(len(arr) + 1):
            # when i reaches the array length, it is an indication that
            # all the elements have been processed, and the remaining
            # elements in the stack should now be popped out.
        
            while stack and (i == len(arr) or arr[stack[-1]] >= arr[i]):
                
                # Notice the sign ">=". This ensures that no contribution
                # is counted twice. Right_boundary takes equal or smaller
                # elements into account while left_boundary takes only the
                # strictly smaller elements into account
                
                mid = stack.pop()
                left_boundary = -1 if not stack else stack[-1]
                right_boundary = i
                
                # count of subarrays where mid is the minimum element
                count = (mid - left_boundary) * (right_boundary - mid)
                ans += (count * arr[mid])
            
            stack.append(i)
            
        return ans % MOD
        