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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode preHead(-1);
        preHead.next = head;
        ListNode *ptr = &preHead;
        while (ptr != NULL && ptr->next != NULL) {
            while (ptr->next != NULL && ptr->next->val == val) {
                ListNode *del = ptr->next;
                ptr->next = del->next;
                del->next = NULL;
                delete del;
            }
            ptr = ptr->next;
        }
        head = preHead.next;
        preHead.next = NULL;
        return head;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *preHead = new ListNode(-1);
        preHead.next = head;
        for (ListNode *i = preHead; i && i->next; ) {
            if (i->next->val = val) {
                ListNode *del = i->next;
                i->next = del->next;
                del->naxt = NULL;
                delete del;
            } else {
                i = i->next;
            }
        }
    }
};