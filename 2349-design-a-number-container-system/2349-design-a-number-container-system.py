class NumberContainers:

    def __init__(self):
        # Initializing the defaultdict with SortedSet and the regular dictionary
        # Map from number to set of indices
        self.num_to_idx = defaultdict(SortedSet)
        # Map from index to number
        self.idx_to_num = dict()

    def change(self, index: int, number: int) -> None:
        # If index already has a number, remove it from the old number's index set
        if index in self.idx_to_num:
            prev_num = self.idx_to_num[index]
            self.num_to_idx[prev_num].remove(index)
            if not self.num_to_idx[prev_num]:
                del self.num_to_idx[prev_num]

        # Update the number and add the index to the new number's set
        self.idx_to_num[index] = number
        self.num_to_idx[number].add(index)

    def find(self, number: int) -> int:
        # Return the smallest index for the given number, or -1 if not found
        if number in self.num_to_idx and self.num_to_idx[number]:
            return self.num_to_idx[number][0]
        return -1

# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)