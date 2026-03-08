class LogSystem:

    def __init__(self):
        self.logs = []  # List of [timestamp, id]
        

    def put(self, id: int, timestamp: str) -> None:
        st = [int(x) for x in timestamp.split(":")]
        ts_val = self.convert(st)
        self.logs.append((ts_val, id))
    
    def convert(self, st: List[int]) -> int:
        # Adjust month and day: subtract 1 if non-zero
        m_adj = st[1] - 1 if st[1] != 0 else 0
        d_adj = st[2] - 1 if st[2] != 0 else 0
    
        # Calculate normalized timestamp value (seconds-equivalent)
        return ((st[0] - 1999) * (31 * 12) * 24 * 60 * 60 +
                m_adj * 31 * 24 * 60 * 60 +
                d_adj * 24 * 60 * 60 +
                st[3] * 60 * 60 +
                st[4] * 60 +
                st[5])

    def retrieve(self, start: str, end: str, granularity: str) -> List[int]:
        start = self.criteria(start, granularity, False)
        end = self.criteria(end, granularity, True)

        ans = []
        for ts_val, id in self.logs:
            if start <= ts_val < end:   # [start, end) range match
                ans.append(id)
        
        return ans
    
    def criteria(self, start: str, granularity: str, end: bool) -> int:
        gra_map = {
            "Year": 0,
            "Month": 1,
            "Day": 2,
            "Hour": 3,
            "Minute": 4,
            "Second": 5
        }
        gra_idx = gra_map[granularity]

        # Initialize base timestamp components
        base = ["1999", "00", "00", "00", "00", "00"]
        parts = start.split(":")

        # Set relevant parts up to granularity level
        for i in range(gra_idx + 1):
            base[i] = parts[i]

        # Convert to integers and adjust end boundary
        t = [int(x) for x in base]
        if end:
            t[gra_idx] += 1
        
        return self.convert(t)


# Your LogSystem object will be instantiated and called as such:
# obj = LogSystem()
# obj.put(id,timestamp)
# param_2 = obj.retrieve(start,end,granularity)