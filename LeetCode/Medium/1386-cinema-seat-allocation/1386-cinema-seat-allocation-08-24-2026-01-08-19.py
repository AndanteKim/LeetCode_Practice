class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        left, mid, right = 0b11110000, 0b11000011, 0b00001111
        occupied = defaultdict(int)
        for r, seat in reservedSeats:
            if 2 <= seat <= 9:
                occupied[r] |= 1 << (seat - 2)
        
        ans = (n - len(occupied)) * 2

        for r, bitmask in occupied.items():
            if (
                (bitmask | left) == left
                or (bitmask | mid) == mid
                or (bitmask | right) == right
            ):
                ans += 1
        
        return ans