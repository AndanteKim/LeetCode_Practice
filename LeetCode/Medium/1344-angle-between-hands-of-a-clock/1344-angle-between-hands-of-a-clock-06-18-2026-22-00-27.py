class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        one_min_angle, one_hour_angle = 6, 30
        min_angle = one_min_angle * minutes
        hour_angle = (hour % 12 + minutes / 60) * one_hour_angle

        diff = abs(hour_angle - min_angle)

        return min(diff, 360 - diff)