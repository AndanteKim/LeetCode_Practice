class PhoneDirectory:

    def __init__(self, maxNumbers: int):
        self.is_available = dict()
        for i in range(maxNumbers):
            self.is_available[i] = True

    def get(self) -> int:
        for num, ok in self.is_available.items():
            if ok:
                self.is_available[num] = False
                return num

        return -1

    def check(self, number: int) -> bool:
        return self.is_available[number]

    def release(self, number: int) -> None:
        self.is_available[number] = True

# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)