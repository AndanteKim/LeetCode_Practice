class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        freq, n = dict(), len(arr)
        for i in range(n):
            freq[arr[i]] = freq.get(arr[i], 0) + 1
        
        distinct = []
        for i in range(n):
            if freq[arr[i]] == 1:
                distinct.append(arr[i])
                
        return distinct[k - 1] if k <= len(distinct) else ""