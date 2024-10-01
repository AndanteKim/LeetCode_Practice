class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        freq = dict()
        
        # Store the count of remainders in a map
        for num in arr:
            target = ((num % k) + k) % k
            freq[target] = freq.get(target, 0) + 1
            
        for num in arr:
            target = ((num % k) + k) % k
            
            # If the remainder for an element is 0, then the count of numbers that give this remainder must be even.
            if target == 0:
                if freq[target] % 2 == 1:
                    return False
            
            # If the remainder target and k - rem don't have the same count then pairs cannot be made.
            elif freq[target] != freq.get(k - target, 0):
                return False
            
        return True