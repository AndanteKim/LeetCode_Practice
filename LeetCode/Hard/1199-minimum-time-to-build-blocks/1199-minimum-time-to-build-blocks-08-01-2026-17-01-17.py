class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        heapify(blocks)

        while len(blocks) > 1:
            x = heappop(blocks)
            y = heappop(blocks)

            heappush(blocks, split + y)

        return heappop(blocks)