class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        flip_queue = deque() # Queue to keep track of flips
        flipped, res = 0, 0  # Current flip state, total number of flips
        
        for i in range(len(nums)):
            # Remove the effect of the oldest flip if it's out of the current window
            if i >= k:
                flipped ^= flip_queue[0]
                
            # If the current bit is 0 (i.e., it needs to be flipped)
            if flipped == nums[i]:
                # If we cannot flip a subarray starting at index i
                if i + k > n:
                    return -1
                
                # Add a flip at this position
                flip_queue.append(1)
                flipped ^= 1 # Toggle the flipped state
                res += 1    # Increment the flip count
            else:
                flip_queue.append(0)
                
            # Remove the oldest flip effect if the queue is larger than k
            if len(flip_queue) > k:
                flip_queue.popleft()
                
        return res
                