class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        ans, n = [], len(currentState)
        
        for i in range(n - 1):
            if currentState[i] == currentState[i + 1]:
                if currentState[i] == '+':
                    ans.append(currentState[:i] + "--" + currentState[i + 2:])
        
        return ans