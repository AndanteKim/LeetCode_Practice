class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        ans, i = [], 2
        
        if finalSum % 2 == 0:
            while i <= finalSum:
                ans.append(i)
                finalSum -= i
                i += 2
            ans[-1] += finalSum
        return ans
        