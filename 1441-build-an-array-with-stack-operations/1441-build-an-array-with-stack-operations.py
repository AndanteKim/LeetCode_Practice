class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        i, start, target_length, ans = 1, 0, len(target), []
                
        while i <= n and start < target_length:
            ans.append("Push")
            if i == target[start]:
                start += 1
            else:
                ans.append("Pop")
            i += 1
                
        return ans