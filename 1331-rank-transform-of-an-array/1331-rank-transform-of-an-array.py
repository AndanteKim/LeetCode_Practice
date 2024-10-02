class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = arr[:]
        rank.sort()
        mapping, ans, i = dict(), [], 1
        for num in rank:
            if num in mapping:
                continue
            mapping[num] = i
            i += 1
        
        for num in arr:
            ans.append(mapping[num])
        
        return ans