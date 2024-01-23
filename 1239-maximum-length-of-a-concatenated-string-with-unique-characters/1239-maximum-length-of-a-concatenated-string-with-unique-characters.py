class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def backtrack(i: int, exist_char: Set[int]) -> int:
            if i == n:
                return 0
            
            curr_length = 0
            choose_ch = deepcopy(exist_char)
            for ch in arr[i]:
                if ch in choose_ch:
                    curr_length = 0
                    break
                choose_ch.add(ch)
                curr_length += 1
            
            max_length = max(curr_length + backtrack(i + 1, choose_ch), backtrack(i + 1, exist_char))
            
            return max_length
        
        n = len(arr)
        return backtrack(0, set())