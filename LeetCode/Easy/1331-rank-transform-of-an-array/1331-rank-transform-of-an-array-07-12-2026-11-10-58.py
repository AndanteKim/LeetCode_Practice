class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank_map, n = dict(), len(arr)
        nums, rank = sorted(set(arr)), 1
        ans = [0] * n

        for num in nums:
            rank_map[num] = rank
            rank += 1
        
        for i in range(n):
            ans[i] = rank_map[arr[i]]
        
        return ans