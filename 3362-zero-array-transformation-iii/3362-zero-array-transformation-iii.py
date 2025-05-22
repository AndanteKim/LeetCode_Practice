class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        queries.sort()
        heap, m, n = [], len(queries), len(nums)
        delta_arr = [0] * (n + 1)
        ops, j = 0, 0

        for i, num in enumerate(nums):
            ops += delta_arr[i]

            while j < m and queries[j][0] == i:
                heappush(heap, -queries[j][1])
                j += 1
            
            while ops < num and heap and -heap[0] >= i:
                ops += 1
                delta_arr[-heappop(heap) + 1] -= 1

            if ops < num:
                return -1

        return len(heap)
