class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        arr_cp = arr[:]
        heapify(arr_cp)
        rank, prev = 0, float('-inf')
        rank_map = dict()

        while arr_cp:
            curr = heappop(arr_cp)

            if prev < curr:
                rank += 1
                rank_map[curr] = rank
                prev = curr
            else:
                rank_map[curr] = rank
        
        n = len(arr)
        ans = [0] * n

        for i in range(n):
            ans[i] = rank_map[arr[i]]

        return ans