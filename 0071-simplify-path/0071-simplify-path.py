class Solution:
    def simplifyPath(self, path: str) -> str:
        stack, ans = [], ""
        i = 0
        while i < len(path):
            if path[i] == '/':
                i += 1
                continue
            temp = ""
            while i < len(path) and path[i] != '/':
                temp += path[i]
                i += 1
            
            if temp == '.':
                continue
            elif temp == "..":
                if stack:
                    stack.pop()
            else:
                stack.append(temp)
            
        return "/" if not stack else "/" + "/".join(stack)