class NumberContainers:

    def __init__(self):
        # Map to store number -> min heap of indices
        self.num_to_idx = defaultdict(list)
        # Map to store index -> number
        self.idx_to_num = dict()

    def change(self, index: int, number: int) -> None:
        # Update index to number mapping
        self.idx_to_num[index] = number

        # Add index to the min heap for this number
        heappush(self.num_to_idx[number], index)

    def find(self, number: int) -> int:
        # If number doesn't exist in our map
        if not self.num_to_idx[number]:
            return -1

        # Keep checking top element until we find valid index
        while self.num_to_idx[number]:
            idx = self.num_to_idx[number][0]

            # If index still maps to our target numbers, return it
            if self.idx_to_num.get(idx) == number:
                return idx        

            # Otherwise remove this stale index
            heappop(self.num_to_idx[number])

        return -1

# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)