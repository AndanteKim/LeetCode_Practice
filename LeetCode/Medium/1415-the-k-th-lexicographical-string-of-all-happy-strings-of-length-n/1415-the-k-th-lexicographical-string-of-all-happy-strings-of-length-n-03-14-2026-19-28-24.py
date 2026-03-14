class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        self.curr_str, self.ans = "", ""
        self.idx_in_sorted_list = 0

        # Generate happy strings and track the k-th string
        self.backtrack(n, k)

        return self.ans

    def backtrack(self, n: int, k: int) -> None:
        # Base case
        if len(self.curr_str) == n:
            # Increment the count of generated strings
            self.idx_in_sorted_list += 1

            # If this is the k-th string, store it in the result
            if self.idx_in_sorted_list == k:
                self.ans = self.curr_str
            return

        for ch in ["a", "b", "c"]:
            if (
                len(self.curr_str) > 0 and self.curr_str[-1] == ch
                ):
                continue
            
            self.curr_str += ch

            # Generate the next character recursively 
            self.backtrack(n, k)

            # If the result is found, stop further processing
            if self.ans != "":
                return
            
            # Backtrack by removing the last character
            self.curr_str = self.curr_str[:-1]

        