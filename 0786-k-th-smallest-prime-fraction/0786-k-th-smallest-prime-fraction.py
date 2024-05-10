class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        candidates, n = [], len(arr)
        
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                candidates.append((arr[i], arr[j]))
        candidates.sort(key = lambda x: x[0] / x[1])
        
        return [candidates[k - 1][0], candidates[k - 1][1]]