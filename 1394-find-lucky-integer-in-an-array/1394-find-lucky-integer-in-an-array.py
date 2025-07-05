class Solution:
    def findLucky(self, arr: List[int]) -> int:
        ans = -1
        freq = Counter(arr)

        for num, val in freq.items():
            if num == val:
                ans = max(ans, num)

        return ans