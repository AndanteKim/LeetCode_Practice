class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        # Prepare heap of building time
        heapify(blocks)
        
        # Make sibling blocks until we are left with only one root node
        while len(blocks) > 1:
            # Pop two minimum The time of the abstracted sub-root will be
            # split + max(x, y) which is split + y
            x = heappop(blocks)
            y = heappop(blocks)
            heappush(blocks, split + y)
            
        # Time of final root node
        return heappop(blocks)