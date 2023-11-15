class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        if arr[0] != 1:
            arr[0] = 1
        ans, prev = 1, -1
        
        
        for i in range(len(arr) - 1):
            if abs(arr[i + 1] - arr[i]) > 1:
                arr[i + 1] = arr[i] + 1
            
            ans = max(ans, arr[i], arr[i + 1])
            
        return ans