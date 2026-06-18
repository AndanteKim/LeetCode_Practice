class Solution {
public:
    double angleClock(int hour, int minutes) {
        int oneMinAngle = 6, oneHourAngle = 30;
        int minAngle = oneMinAngle * minutes;
        double hourAngle = (hour % 12 + (double)minutes / 60) * 30;
        double diff = abs(minAngle - hourAngle);

        return min(diff, 360 - diff);
    }
};