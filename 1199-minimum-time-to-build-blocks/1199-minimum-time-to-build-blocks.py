class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        # sort array in descending order of the required time
        blocks.sort(reverse = True)
        
        # If can be built in "limit"
        def possible(limit: int) -> bool:
            # build all blocks starting with 1 worker
            worker = 1
            
            for i, time in enumerate(blocks):
                # If no worker or no sufficient time
                if worker <= 0 or time > limit:
                    return False
                
                # keep splitting and producing workers as long as
                # we are within the limit for this block
                while time + split <= limit:
                    limit -= split
                    worker *= 2
                    
                    # sufficient workers for the remaining block
                    if worker >= len(blocks) - i:
                        return True
                
                # build block
                worker -= 1
            
            # all blocks build
            return True
        
        # binary search algorithm
        left, right = blocks[0], ceil(log2(len(blocks))) * split + blocks[0]
        
        while left < right:
            mid = (left + right) >> 1
            if possible(mid):
                right = mid
            else:
                left = mid + 1
        
        # right is the minimum time when the task is possible
        return int(right)