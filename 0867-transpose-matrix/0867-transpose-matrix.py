class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return [row for row in zip(*matrix)]