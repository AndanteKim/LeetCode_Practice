class Solution:
    def numSquares(self, n: int) -> int:
        # list of square numbers that are less than 'n'
        square_nums = [i * i for i in range(1, int(n ** 0.5) + 1)]
        level, queue = 0, {n}
        
        while queue:
            level += 1
            #! important: use set() instead of list() to eliminate the redundancy.
            # which would even provide a 5-times speedup, 200ms vs. 1000ms.
            next_queue = set()
            
            # construct the queue for the next level
            for remainder in queue:
                for square_num in square_nums:
                    if remainder == square_num:
                        return level # find the node!
                    elif remainder < square_num:
                        break
                    else:
                        next_queue.add(remainder - square_num)
            
            queue = next_queue
        return level