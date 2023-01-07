class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        ans, length = 0, len(arr)
        
        for i in range(1, length+1, 2):
            for j in range(length):
                if len(arr[j:j+i]) != i: break
                ans += sum(arr[j:j+i])
        return ans
            