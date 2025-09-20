class Router:

    def __init__(self, memoryLimit: int):
        self.size = memoryLimit
        self.packets = {}
        self.count = defaultdict(list)
        self.queue = deque()


    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        key = self._encode(source, destination, timestamp)
        if key in self.packets:
            return False
        if len(self.packets) >= self.size:
            self.forwardPacket()
        self.packets[key] = [source, destination, timestamp]
        self.queue.append(key)
        self.count[destination].append(timestamp)
        return True

    def forwardPacket(self) -> List[int]:
        if not self.packets:
            return []
        key = self.queue.popleft()
        packet = self.packets.pop(key)
        dest = packet[1]
        self.count[dest].pop(0)
        return packet

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        timestamps = self.count.get(destination, [])
        if not timestamps:
            return 0
        left = bisect.bisect_left(timestamps, startTime)
        right = bisect.bisect_right(timestamps, endTime)
        return right - left
    
    def _encode(self, source: int, destination: int, timestamp: int) -> int:
        return (source << 40) | (destination << 20) | timestamp


# Your Router object will be instantiated and called as such:
# obj = Router(memoryLimit)
# param_1 = obj.addPacket(source,destination,timestamp)
# param_2 = obj.forwardPacket()
# param_3 = obj.getCount(destination,startTime,endTime)