class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


def arrayToList(array):
    if not array:
        return None
    for i in range(len(array)):
        if i == 0:
            head = ListNode(array[i])
            pointer = head
        else:
            pointer.next = ListNode(array[i])
            pointer = pointer.next

    return head


def printList(head):
    if head is None:
        print None
        return 
    pointer = head
    while pointer.next is not None:
        print pointer.val, "->",
        pointer = pointer.next
    print pointer.val