class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        frequencies = defaultdict(int)
        
        for n in arr:
            frequencies[n] += 1
        
        pairs = [(k, v) for k, v in frequencies.items()]
        pairs.sort(key = lambda x: -x[1])
        print(pairs)
        while k != 0:
            key, val = pairs.pop()
            val -= 1
            if val > 0:
                pairs.append((key, val))
            k -= 1
        return len(pairs)