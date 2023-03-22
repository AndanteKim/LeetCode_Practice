# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def get_hostname(self, url: str):
        return url.split('/')[2]
    
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        start_hostname = self.get_hostname(startUrl)
        queue = deque([startUrl])
        visited = set([startUrl])
        
        while queue:
            url = queue.popleft()
            for next_url in htmlParser.getUrls(url):
                if self.get_hostname(next_url) == start_hostname and next_url not in visited:
                    queue.append(next_url)
                    visited.add(next_url)
        return visited