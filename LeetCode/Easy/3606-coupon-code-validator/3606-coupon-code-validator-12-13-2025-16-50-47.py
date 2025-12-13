class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        n, ans = len(code), []
        categories = defaultdict(list)

        for code, b_l, is_active in zip(code, businessLine, isActive):
            is_valid = True if code != "" else False
            for c in code:
                if not (c.islower() or c.isupper() or c.isdigit() or c == '_'):
                    is_valid = False
                    break

            if is_valid and is_active:
                heappush(categories[b_l], code)

        for category in ["electronics", "grocery", "pharmacy", "restaurant"]:
            while categories[category]:
                ans.append(heappop(categories[category]))
        return ans