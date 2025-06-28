class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        ans, min_heap = [], []
        for i, num in enumerate(nums):
            if len(min_heap) >= k:
                if min_heap[0][0] < num:
                    heappop(min_heap)
                    heappush(min_heap, (num, i))
            else:
                heappush(min_heap, (num, i))
        
        min_heap.sort(key = lambda x : x[1])
        for (num, i) in min_heap:
            ans.append(num)

        return ans