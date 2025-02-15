class ProductOfNumbers:
    # Stores cumulative product of the stream
    def __init__(self):
        # Initialize the product list with 1 to handle multiplication logic
        self.prefix_prod, self.size = [1], 0

    def add(self, num: int) -> None:
        if num == 0:
            # If num is 0, reset the cumulative products since multiplication
            # with 0 invalidates previous products
            self.prefix_prod = [1]
            self.size = 0
        else:
            # Append the cumulative product of the current number with the last product
            self.prefix_prod.append(self.prefix_prod[-1] * num)
            self.size += 1

    def getProduct(self, k: int) -> int:
        # Check if the requested product length exceeds the size of the valid product list
        # Otherwise, compute the product of the last k elements using division
        return 0 if k > self.size else self.prefix_prod[self.size] // self.prefix_prod[self.size - k]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)