class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        min_heap, max_heap = [], []
        
        for i in range(len(arrays)):
            mn, mx = arrays[i][0], arrays[i][-1]
            heappush(min_heap, (mn, i))
            heappush(max_heap, (-mx, i))
        
        mn, mx = float('inf'), float('-inf')
        idx1, idx2 = -1, -1
        while min_heap and max_heap:
            if mn == float('inf') and idx1 == -1:
                mn, idx1 = heappop(min_heap)
            if mx == float('-inf') and idx2 == -1:
                mx, idx2 = heappop(max_heap)
            
            if idx1 == idx2:
                if abs(mn - min_heap[0][0]) < abs(mx - max_heap[0][0]):
                    mn, idx1 = float('inf'), -1
                else:
                    mx, idx2 = float('-inf'), -1
            else:
                return abs(mx + mn)
        
        return 0