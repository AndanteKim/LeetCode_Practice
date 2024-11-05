class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        # Sort the folders alphabetically
        folder.sort()
        
        # Initialize the result list 
        res = [folder[0]]
        
        for i in range(1, len(folder)):
            last_folder = res[-1]
            last_folder += '/'
            
            # Check if the current folder starts with the last added folder path
            if not folder[i].startswith(last_folder):
                res.append(folder[i])
                
        # Return the result containing only non-sub-folders
        return res