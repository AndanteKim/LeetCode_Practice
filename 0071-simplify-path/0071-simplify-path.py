class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        
        for section in path.split('/'):
            if section == "..":
                if stack:
                    stack.pop()
            elif section == '.' or not section:
                continue
            else:
                stack.append(section)
        ans = "/" + "/".join(stack)
        return ans