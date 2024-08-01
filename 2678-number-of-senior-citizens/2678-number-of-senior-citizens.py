class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return sum((s[11:13] > '60') for s in details)