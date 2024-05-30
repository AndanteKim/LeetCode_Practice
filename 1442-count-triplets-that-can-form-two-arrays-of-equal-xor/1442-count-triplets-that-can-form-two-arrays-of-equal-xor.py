class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n, count = len(arr), 0
        
        # Iterate over each possible starting index i
        for start in range(n - 1):
            # Initialize XOR value for the subarray from start to mid - 1
            xor_A = 0
            
            # Iterate over each possible middle index j
            for mid in range(start + 1, n):
                # Update xor_A to include arr[mid - 1]
                xor_A ^= arr[mid - 1]
                
                # Initialize XOR value for the subarray from mid to end
                xor_B = 0
                
                # Iterate over each possible ending index k (starting from mid)
                for end in range(mid, n):
                    # Update xor_B to include arr[end]
                    xor_B ^= arr[end]
                    
                    # Found a valid triple (start, mid, end)
                    if xor_A == xor_B:
                        count += 1
        
        return count