class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        def is_letter(c: str) -> bool:
            return 'a' <= c <= 'z'

        def expr() -> Set[str]:
            nonlocal i
            ret = set()
            while True:
                ret |= term()

                if i < n and expression[i] == ',':
                    i += 1
                    continue
                else:
                    break
            return ret
        
        def term() -> Set[str]:
            nonlocal i
            ret = {""}

            while i < n and (expression[i] == '{' or is_letter(expression[i])):
                tmp, sub = set(), item()
                for left in ret:
                    for right in sub:
                        tmp.add(left + right)
                ret = tmp
            return ret
        
        def item() -> Set[str]:
            nonlocal i
            ret = set()
            if expression[i] == '{':
                i += 1
                ret = expr()
            else:
                ret = {expression[i]}
            i += 1
            return ret
        
        i, n = 0, len(expression)
        ret = expr()
        return sorted(list(ret))