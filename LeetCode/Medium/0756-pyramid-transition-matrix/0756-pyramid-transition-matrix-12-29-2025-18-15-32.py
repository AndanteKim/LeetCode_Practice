class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        def backtrack(idx: int, new_row: str, origin_row: str, length: int) -> bool:
            if length == 1:
                return True

            if idx == length - 1:
                if new_row in dp:
                    return dp[new_row]
                dp[new_row] = backtrack(0, "", new_row, length - 1)
                return dp[new_row]
            
            # Check in mapping what all possibilities are present
            key = origin_row[idx : idx + 2]

            # Not found a valid allowed
            if len(mapping[key]) == 0:
                return False


            for x in mapping[key]:
                # If any ans gives us True, we can break from loop and return True
                if backtrack(idx + 1, new_row + x, origin_row, length):
                    return True

            return False

        n, mapping, dp = len(bottom), defaultdict(list), dict()
        for triangle in allowed:
            mapping[triangle[0:2]].append(triangle[2])
        return backtrack(0, "", bottom, n)