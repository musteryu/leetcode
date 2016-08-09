import sys
sys.path.append("../lib")
from ListNode import *


class Solution(object):

    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        stack = []
        prehead = ListNode(None)
        preptr = prehead
        ptr = head
        while ptr is not None:
            stack.append(ptr)
            ptr = ptr.next
            if len(stack) == k:
                while len(stack) > 0:
                    preptr.next = stack.pop()
                    preptr = preptr.next

        if len(stack) != 0:
            for node in stack:
                preptr.next = node
                preptr = preptr.next
        else:
            preptr.next = None
        return prehead.next


if __name__ == '__main__':
    testhead = arrayToList(range(100))
    printList(Solution().reverseKGroup(testhead, 6))
