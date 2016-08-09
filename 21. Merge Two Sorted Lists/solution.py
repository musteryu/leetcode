# Definition for singly-linked list.
class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        pointer1, pointer2 = l1, l2
        prehead = ListNode(None)
        pointerOfResult = prehead
        while pointer1 is not None and pointer2 is not None:
            if pointer1.val < pointer2.val:
                pointerOfResult.next = pointer1
                pointer1.next, pointer1 = None, pointer1.next
            else:
                pointerOfResult.next = pointer2
                pointer2.next, pointer2 = None, pointer2.next
            pointerOfResult = pointerOfResult.next
        if pointer1 is not None:
            pointerOfResult.next = pointer1
        elif pointer2 is not None:
            pointerOfResult.next = pointer2
        return prehead.next


def arrayToList(array):
    for i in range(len(array)):
        if i == 0:
            head = ListNode(array[i])
            pointer = head
        else:
            pointer.next = ListNode(array[i])
            pointer = pointer.next

    return head


def printList(head):
    pointer = head
    while pointer.next is not None:
        print pointer.val, "->",
        pointer = pointer.next
    print pointer.val


if __name__ == '__main__':
    so = Solution()
    l1 = [1, 3, 5, 7, 9, 12, 15, 17]
    l2 = [2, 4, 6, 8, 10]
    printList(so.mergeTwoLists(arrayToList(l1), arrayToList(l2)))
