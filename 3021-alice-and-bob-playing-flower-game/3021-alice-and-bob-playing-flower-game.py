class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        n_even, m_even = n >> 1, m >> 1
        n_odd, m_odd = n - n_even, m - m_even

        return n_even * m_odd + n_odd * m_even