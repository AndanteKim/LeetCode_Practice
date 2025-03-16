class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        # Count the frequency of each rank using a Counter
        count = Counter(ranks)

        # Create a Min-heap storing [time, rank, n, count];
        # - time: time for the next repair
        # - rank: mechanic's rank
        # - n: cars repaired by this mechanic
        # - count: number of mechanics with this rank
        # Initial time = rank (as rank * 1 ^ 2 = rank)
        min_heap = [[rank, rank, 1, count[rank]] for rank in count]
        heapify(min_heap)

        # Process until all cars are repaired
        while cars > 0:
            # Pop the mechanic with the smallest current repair time
            time, rank, n, count = heappop(min_heap)

            # Deduct the number of cars repaired by this mechanic group
            cars -= count

            # Increment the number of cars repaired by this mechanic
            n += 1

            # Push the updated repair time back into the heap
            # The new repair time is rank * n ^ 2 (since time increases quadratically with n)
            heappush(min_heap, [rank * n * n, rank, n, count])

        return time

