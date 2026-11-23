class ProductOfNumbers:

    def __init__(self):
        self.prods, self.size = [1], 0

    def add(self, num: int) -> None:
        if num == 0:
            self.prods, self.size = [1], 0
        else:
            self.prods.append(self.prods[-1] * num)
            self.size += 1

    def getProduct(self, k: int) -> int:
        return 0 if k > self.size else self.prods[self.size] // self.prods[self.size - k]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)