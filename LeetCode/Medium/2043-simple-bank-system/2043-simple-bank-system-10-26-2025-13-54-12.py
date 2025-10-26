class Bank:

    def __init__(self, balance: List[int]):
        self.n, self.balance = len(balance), balance

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if self.not_available_transaction(account1, money) or account2 > self.n:
            return False

        self.balance[account1 - 1] -= money
        self.balance[account2 - 1] += money

        return True

    def deposit(self, account: int, money: int) -> bool:
        if account > self.n:
            return False
        
        self.balance[account - 1] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        if self.not_available_transaction(account, money):
            return False
        
        self.balance[account - 1] -= money
        return True

    def not_available_transaction(self, account: int, money: int) -> bool:
        return account > self.n or self.balance[account - 1] < money


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)