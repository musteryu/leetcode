/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *curr = head, *next = head->next;
        head = nullptr;
        while (curr != nullptr) {
            curr->next = head;
            head = curr;
            curr = next;
            if (next) next = next->next;
        }
        return head;
    }
};