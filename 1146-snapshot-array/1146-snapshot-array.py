class SnapshotArray:

    def __init__(self, length: int):
        self.id = 0
        self.snapshot = [[[0, 0]] for _ in range(length)]

    def set(self, index: int, val: int) -> None:
        self.snapshot[index].append([self.id, val])

    def snap(self) -> int:
        self.id += 1
        return self.id - 1

    def get(self, index: int, snap_id: int) -> int:
        left, right = 0, len(self.snapshot[index])
        
        while left < right:
            mid = (left + right) // 2
            if [snap_id, 10 ** 9] < self.snapshot[index][mid]:
                right = mid
            else:
                left = mid + 1
        
        return self.snapshot[index][left - 1][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)