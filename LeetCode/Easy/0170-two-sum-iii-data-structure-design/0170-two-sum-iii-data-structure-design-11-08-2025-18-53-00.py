class TwoSum:

    def __init__(self):
        self.cache, self.elements = set(), dict()

    def add(self, number: int) -> None:
        self.elements[number] = self.elements.get(number, 0) + 1

    def find(self, value: int) -> bool:
        if value in self.cache:
            return True

        for elem, freq in self.elements.items():
            if (value - elem) in self.elements:
                if elem == (value >> 1) and self.elements[elem] <= 1:
                    continue
                self.cache.add(value)
                return True

        return False
        


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)