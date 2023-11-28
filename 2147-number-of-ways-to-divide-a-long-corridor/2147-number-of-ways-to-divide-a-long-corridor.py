class Solution:
    def numberOfWays(self, corridor: str) -> int:
        
        MOD, indices = 1_000_000_007, []
        for i, thing in enumerate(corridor):
            if thing == 'S':
                indices.append(i)
        
        # When division is not possible
        if indices == [] or len(indices) % 2 == 1:
            return 0
        
        # Total number of ways
        count = 1

        # Take the product of non-paired neighbors
        prev_pair_last, curr_pair_first = 1, 2
        while curr_pair_first < len(indices):
            count *= (indices[curr_pair_first] - indices[prev_pair_last])
            count %= MOD
            prev_pair_last += 2
            curr_pair_first += 2

        # Return the number of ways
        return count