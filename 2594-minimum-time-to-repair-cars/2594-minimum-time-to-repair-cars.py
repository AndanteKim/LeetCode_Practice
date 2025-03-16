class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        # The minimum possible time is 1,
        # and the maximum possible time is when the slowest mechanic(highest rank) repairs all cars.
        low, high = 1, ranks[0] * cars * cars

        # Perform binary search to find the minimum time required
        while low < high:
            mid = low + ((high - low) >> 1)
            cars_repaired = 0

            for rank in ranks:
                cars_repaired += int((mid / rank) ** 0.5)
            
            # If the total cars repaired is less than required, increase the time.
            if cars_repaired < cars:
                low = mid + 1
            else:
                high = mid  # Otherwise, try a smaller time.
        
        return low