class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        # recursive function to generate the desired sequence
        def find_lexicographically_largest_sequence(curr_idx: int, res_seq: List[int], is_number_used: List[bool]) -> None:
            # If we have filled all positions, return true indicating success
            if curr_idx == len(res_seq):
                return True

            # If the current position is already filled, move to the next index
            if res_seq[curr_idx] != 0:
                return find_lexicographically_largest_sequence(
                    curr_idx + 1,
                    res_seq,
                    is_number_used,
                )

            # Attempt to place numbers from n to 1 for a lexicographically largest result
            for num_to_place in range(n, 0, -1):
                if is_number_used[num_to_place]:
                    continue
                
                is_number_used[num_to_place] = True
                res_seq[curr_idx] = num_to_place

                # If placing number 1, move to the next index directly
                if num_to_place == 1:
                    if find_lexicographically_largest_sequence(
                        curr_idx + 1,
                        res_seq,
                        is_number_used
                    ):
                        return True
                # Place larger numbers at two positions if valid
                elif (
                    curr_idx + num_to_place < len(res_seq)
                    and res_seq[curr_idx + num_to_place] == 0
                ):
                    res_seq[curr_idx + num_to_place] = num_to_place

                    if find_lexicographically_largest_sequence(
                        curr_idx + 1,
                        res_seq,
                        is_number_used,
                    ):
                        return True
                    
                    # Undo the placement for backtracking
                    res_seq[curr_idx + num_to_place] = 0
                
                # Undo current placement and mark the number as unused
                res_seq[curr_idx] = 0
                is_number_used[num_to_place] = False
            
            return False

        # Initialize the result sequence with size 2 * n - 1 filled with 0s
        # Keep track of which numbers are already placed in the sequence 
        res_seq, is_number_used = [0] * (2 * n - 1), [False] * (n + 1)

        # Start recursive backtracking to construct the sequence
        find_lexicographically_largest_sequence(0, res_seq, is_number_used)
        
        return res_seq