import sys
sys.path.append("../lib")
from ListNode import *

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prehead = ListNode(None)
        prehead.next = head
        preptr = prehead
        ptr = head
        stack = []
        while ptr != None:
            stack.append(ptr)
            ptr = ptr.next
            # print ptr if ptr is None else ptr.val
            if len(stack) == 2:
                preptr.next = stack.pop()
                preptr.next.next = stack.pop()
                preptr = preptr.next.next
        if len(stack) == 1:
            preptr.next = stack.pop()
            preptr = preptr.next
        preptr.next = None

        return prehead.next




if __name__ == '__main__':
    so = Solution()
    head = arrayToList(range(10))
    printList(head)
    head = so.swapPairs(head)
    printList(head)
