# Definition for singly-linked list.
class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        pointer = head
        cache = []
        while pointer is not None:
            cache.append(pointer)
            pointer = pointer.next
        listLen = len(cache)
        assert 0 < n <= listLen
        delNode = cache[listLen - n]
        if n < listLen:
            preNode = cache[listLen - n - 1]
            preNode.next = delNode.next
            delNode.next = None
            del(delNode)
        else:
            head = delNode.next
            delNode.next = None
            del(delNode)

        return head


def printList(head):
    pointer = head
    while pointer.next is not None:
        print pointer.val, "->",
        pointer = pointer.next
    print pointer.val

if __name__ == '__main__':
    testhead = ListNode(0)
    pointer = testhead
    testnums = [1, 2, 3, 4, 5, 6, 7, 8]
    for num in testnums:
        pointer.next = ListNode(num)
        pointer = pointer.next
    printList(testhead)
    so = Solution()
    result = so.removeNthFromEnd(testhead, 9)
    printList(result)
