class Solution:
    def findScore(self, nums: List[int]) -> int:
        score, min_heap, marked = 0, [(num, i) for i, num in enumerate(nums)], set()
        heapify(min_heap)
        n = len(nums)
        
        while min_heap:
            num, idx = heappop(min_heap)
            if idx in marked:
                continue
                
            score += num
            marked.add(idx)
            if idx == 0:
                marked.add(idx + 1)
            elif idx == n - 1:
                marked.add(idx - 1)
            else:
                marked.add(idx + 1)
                marked.add(idx - 1)
            
        return score        