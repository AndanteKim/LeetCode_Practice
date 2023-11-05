class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        queue = deque(arr)
        first, second, first_win_count, second_win_count = -1, -1, 0, 0
        
        while first_win_count < k and second_win_count < k:
            if first == -1:
                first = queue.popleft()
            if second == -1:
                second = queue.popleft()
            
            if first > second:
                queue.append(second)
                second = -1
                first_win_count += 1
                second_win_count = 0
            else:
                queue.append(first)
                first = -1
                first_win_count = 0
                second_win_count += 1
                
            if first_win_count > len(arr) or second_win_count > len(arr):
                break
            
        return first if first_win_count else second