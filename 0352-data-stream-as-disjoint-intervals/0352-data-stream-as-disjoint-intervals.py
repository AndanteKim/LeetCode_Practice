class SummaryRanges:

    def __init__(self):
        self.intervals = [[float('-inf'), float('-inf')], [float('inf'), float('inf')]]

    def addNum(self, value: int) -> None:
        i = bisect.bisect(self.intervals, [value])
        
        # ps: previous interval start, pe: previous interval end
        # ns: next interval start, ne: next interval end
        ps, pe = self.intervals[i-1]
        ns, ne = self.intervals[i]
        
        if pe == value - 1 and ns == value + 1:
            self.intervals = self.intervals[:i-1] + [[ps, ne]] + self.intervals[i+1:]
        elif pe == value - 1:
            self.intervals[i-1][1] = value
        elif ns == value + 1:
            self.intervals[i][0] = value
        elif pe < value - 1 and ns > value + 1:
            self.intervals = self.intervals[:i] + [[value, value]] + self.intervals[i:]

    def getIntervals(self) -> List[List[int]]:
        return self.intervals[1:-1]
        
# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()