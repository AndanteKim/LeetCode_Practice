class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n, count, prefix = len(arr), 0, 0
        
        # Dictionaries to store counts and totals of XOR values encountered
        count_map, total_map = defaultdict(int), defaultdict(int)
        count_map[0] = 1
        
        # Iterate through the array
        for i in range(n):
            # Calculate XOR prefix
            prefix ^= arr[i]
            
            # Calculating contribution of current element to the result
            count += count_map[prefix] * i - total_map[prefix]
            
            # Updating total count of current XOR value
            total_map[prefix] += i + 1
            count_map[prefix] += 1
        
        return count