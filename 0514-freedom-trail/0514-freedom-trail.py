class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        # Find the minimum steps between two indices of ring
        def count_steps(curr: int, next: int) -> int:
            steps_between = abs(curr - next)
            steps_around = ring_len - steps_between
            return min(steps_between, steps_around)
        
        # Find the minimum number of steps to spell the keyword
        @lru_cache(maxsize = None)
        def try_lock(ring_i: int, key_i: int, min_steps: int) -> int:
            # If we reach the end of the key, it has been spelled
            if key_i == key_len:
                return 0
            
            # For each occurrence of the character k[key_i] in ring
            # calculate the minimum steps from the ring_i of ring
            for i in range(ring_len):
                if ring[i] == key[key_i]:
                    total_steps = count_steps(ring_i, i) + 1 + \
                    try_lock(i, key_i + 1, float('inf'))
                    min_steps = min(min_steps, total_steps)
            return min_steps
        
        ring_len, key_len = len(ring), len(key)
        return try_lock(0, 0, float('inf'))