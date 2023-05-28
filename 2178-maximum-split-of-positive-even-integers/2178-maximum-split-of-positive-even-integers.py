class Solution:
    def backtrack(self, target: int, currSum: int, path: List[int], start: int) -> bool:
        if currSum == target:
            if len(path) > len(self.ans):
                self.ans = path
            return True
        
        for i in range(start, target + 1, 2):
            if currSum + i > target:
                break
            path.append(i)
            if self.backtrack(target, currSum + i, path, i + 2):
                return True
            path.pop()
    
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        if finalSum & 1:
            return []
        
        self.ans = []
        self.backtrack(finalSum, 0, [], 2)
        return self.ans