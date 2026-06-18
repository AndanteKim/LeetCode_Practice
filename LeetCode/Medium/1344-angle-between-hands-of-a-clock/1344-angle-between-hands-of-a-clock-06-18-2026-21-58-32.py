class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        min_angle = minutes / 60 * 360
        hour_angle = hour * 30 + 0.5 * minutes

        return min(abs(min_angle - hour_angle), 360 - abs(min_angle - hour_angle))