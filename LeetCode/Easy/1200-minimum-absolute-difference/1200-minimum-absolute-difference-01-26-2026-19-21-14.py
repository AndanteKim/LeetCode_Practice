class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_diff, n = float('inf'), len(arr)

        for i in range(n - 1):
            min_diff = min(min_diff, arr[i + 1] - arr[i])
        
        ans = []
        for i in range(n - 1):
            if arr[i + 1] - arr[i] == min_diff:
                ans.append([arr[i], arr[i + 1]])

        return ans