class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        status, highest = 0, 0
        for altitude in gain:
            status += altitude
            highest = max(status, highest)
        return highest