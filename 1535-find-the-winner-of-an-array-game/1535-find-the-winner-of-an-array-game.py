class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        max_element = max(arr)
        curr, winstreak = arr[0], 0
        
        for i in range(1, len(arr)):
            opponent = arr[i]
            if curr > opponent:
                winstreak += 1
            else:
                curr = opponent
                winstreak = 1
            
            if winstreak == k or curr == max_element:
                return curr
        return -1