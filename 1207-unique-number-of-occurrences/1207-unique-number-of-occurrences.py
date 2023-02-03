class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        k = 1000
        freq = [0] * (2 * k + 1)
        
        for num in arr:
            freq[num + k] += 1
        
        freq.sort()
        
        for i in range(2 * k):
            if freq[i] and freq[i] == freq[i+1]:
                return False
        
        return True
        