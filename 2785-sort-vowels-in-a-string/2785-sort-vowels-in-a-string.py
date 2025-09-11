class Solution:
    def sortVowels(self, s: str) -> str:
        min_heap, vowels = [], "aeiouAEIOU"

        for c in s:
            if c in vowels:
                heappush(min_heap, c)

        arr, n = [c for c in s], len(s)

        for i in range(n):
            if arr[i] in vowels:
                arr[i] = heappop(min_heap)

        return "".join(arr)