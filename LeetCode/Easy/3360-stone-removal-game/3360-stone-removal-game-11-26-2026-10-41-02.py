class Solution:
    def canAliceWin(self, n: int) -> bool:
        remain, is_alice_turn = n, True
        for i in range(10, 0, -1):
            if i > remain:
                return False if is_alice_turn else True
            remain -= i
            is_alice_turn = not is_alice_turn

        return False if is_alice_turn else True