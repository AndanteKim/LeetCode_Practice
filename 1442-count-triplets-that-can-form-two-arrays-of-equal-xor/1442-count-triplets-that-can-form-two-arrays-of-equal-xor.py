class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        prefix_xor = [0] + arr
        size, count = len(prefix_xor), 0
        
        # Performing XOR operation on the array elements
        for i in range(1, size):
            prefix_xor[i] ^= prefix_xor[i - 1]
            
        # Dictionaries to store counts and totals of XOR values encountered
        count_map, total_map = defaultdict(int), defaultdict(int)
        
        # Iterate through the array
        for i in range(size):
            # Calculating contribution of current element to the result
            count += (count_map[prefix_xor[i]] * (i - 1) - total_map[prefix_xor[i]])
            
            # Updating total count of current XOR value
            total_map[prefix_xor[i]] += i
            count_map[prefix_xor[i]] += 1
            
        return count
        