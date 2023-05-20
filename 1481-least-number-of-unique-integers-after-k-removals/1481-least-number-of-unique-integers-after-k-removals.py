class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        cnts = Counter(arr)
        ordered = sorted(cnts.values(), reverse = True)
        print(ordered)
        
        while k:
            val = ordered[-1]
            if val <= k:
                k -= val
                ordered.pop()
            else:
                break
        return len(ordered)