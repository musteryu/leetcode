# Definition for singly-linked list.
class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        total = []
        for head in lists:
            total += self.listToArray(head)

        total.sort()

        return self.arrayToList(total)

    def getCurrentMinNode(self, lists):
        tmp = [(i, a) for i, a in enumerate(lists) if a is not None]
        if not tmp:
            return None
        minIndex, minNode = tuple(min(tmp, key=lambda elem: elem[1].val))
        lists[minIndex] = lists[minIndex].next
        return minNode

    def listToArray(self, head):
        tmp = []
        ptr = head
        while ptr != None:
            tmp.append(ptr.val)
            ptr = ptr.next
        return tmp

    def arrayToList(self, array):
        if not array:
            return None
        for i, v in enumerate(array):
            if i == 0:
                head = ListNode(v)
                pointer = head
            else:
                pointer.next = ListNode(v)
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
    test = [[1]]
    testlists = [so.arrayToList(i) for i in test]
    head = so.mergeKLists(testlists)
    printList(head)
