/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        ListNode *oddTail = head, *evenTail = head->next, *ptr = head->next->next;
        while (ptr != nullptr) {
            ListNode *ptrNext = ptr->next;
            ptr->next = oddTail->next;
            oddTail = oddTail->next = ptr;
            evenTail = evenTail->next = ptrNext;
            if (ptrNext != nullptr) {
                ptr = ptrNext->next;
            } else ptr = nullptr;
        }
        return head;
    }
};