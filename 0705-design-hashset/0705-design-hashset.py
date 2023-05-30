class MyHashSet:

    def __init__(self):
        self.dictionary = [0] * (10 ** 6 + 1)

    def add(self, key: int) -> None:
        if self.dictionary[key] == 0:
            self.dictionary[key] += 1

    def remove(self, key: int) -> None:
        if self.dictionary[key] > 0:
            self.dictionary[key] -= 1

    def contains(self, key: int) -> bool:
        return self.dictionary[key] > 0


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)