class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        def count_steps(curr: int, next: int) -> int:
            steps_between = abs(curr - next)
            steps_around = ring_len - steps_between
            return min(steps_between, steps_around)
        
        def try_locks(ring_i: int, key_i: int) -> int:
            # If we have already calculated this sub_problem, return result
            if (ring_i, key_i) in best_steps:
                return best_steps[(ring_i, key_i)]
            
            # If we reach the end of the key_word, it has been spelled
            if key_i == key_len:
                best_steps[(ring_i, key_i)] = 0
                return 0
            
            # For each occurrence of the chracter k[key_index] in ring
            # calculate the minimum steps from the ring_index of ring
            min_steps = float('inf')
            for i in range(ring_len):
                if ring[i] == key[key_i]:
                    min_steps = min(min_steps, count_steps(ring_i, i) + 1\
                                   + try_locks(i, key_i + 1))
            
            best_steps[(ring_i, key_i)] = min_steps
            return min_steps
        
        ring_len, key_len = len(ring), len(key)
        best_steps = dict()
        
        return try_locks(0, 0)