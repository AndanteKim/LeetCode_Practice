class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        n, min_rank, max_rank = len(ranks), ranks[0], ranks[0]
        
        # Frequency list to count meachanics with each rank
        freq = [0] * 101

        for rank in ranks:
            freq[rank] += 1

            # Find min and max rank dynamically
            min_rank = min(min_rank, rank)
            max_rank = max(max_rank, rank)

        # Minimum possible time, Maximum possible time
        low, high, ans = 1, min_rank * cars * cars, float('inf')

        # Perform binary search to find the minimum time required
        while low < high:
            mid, cars_repaired = low + ((high - low) >> 1), 0

            # Calculate the total number of cars that can be repaired in 'mid' time
            for rank in range(1, max_rank + 1):
                cars_repaired += freq[rank] * int((mid / rank) ** 0.5)
            
            # Adjust the search boundaries based on the number of cars repaired
            if cars_repaired >= cars:
                high = mid  # Try to find a smaller time
            else:
                low = mid + 1   # Need more time

        return low