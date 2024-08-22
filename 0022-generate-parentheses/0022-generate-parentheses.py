class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def is_valid(p_str: str) -> bool:
            left_count = 0
            
            for p in p_str:
                if p == '(':
                    left_count += 1
                else:    
                    left_count -= 1
                    
                if left_count < 0:
                    return False
                
            return left_count == 0
        
        ans = []
        queue = deque([""])
        
        while queue:
            curr_str = queue.popleft()
            
            # If the length of curr_str is 2 * n, add it to 'answer' if
            # it's valid.
            if len(curr_str) == 2 * n:
                if is_valid(curr_str):
                    ans.append(curr_str)
                continue
            
            queue.append(curr_str + '(')
            queue.append(curr_str + ')')
    
        return ans