import collections
import heapq
import time

class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tweets = collections.defaultdict(list)
        self.following = collections.defaultdict(set)

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        self.tweets[userId] += (-time.time(), tweetId, userId),

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        hp = []
        for person in self.following[userId] | {userId}:
            if self.tweets[person]:
                size = len(self.tweets[person])
                timestamp, tweetId, personId = self.tweets[person][size-1]
                hp.append((timestamp, tweetId, personId, size-1))
        heapq.heapify(hp)
        res = []
        while hp and len(res) < 10:
            timestamp, tweetId, personId, top = heapq.heappop(hp)
            res += tweetId,
            if top > 0:
                timestamp, tweetId, personId = self.tweets[personId][top-1]
                heapq.heappush(hp, (timestamp, tweetId, personId, top-1))
        return res

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followeeId in self.following[followerId]:
            self.following[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)