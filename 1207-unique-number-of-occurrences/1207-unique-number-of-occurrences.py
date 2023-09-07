class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        d = Counter(arr).values()
        return len(set(d)) == len(d)