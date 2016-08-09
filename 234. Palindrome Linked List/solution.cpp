/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    inline bool isTheSame(ListNode *a, ListNode *b) {
        while (a && b) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return !a && !b;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *aux = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode *slowNext = slow->next;
            slow->next = aux;
            aux = slow;
            slow = slowNext;
        }
        if (fast == nullptr) {
            return isTheSame(slow, aux);
        } else {
            return isTheSame(slow->next, aux);
        }
    }
};

int main() {
    ListNode head(1);
    ListNode tail(2);
    head.next = &tail;
    Solution s;
    cout << s.isPalindrome(&head) << endl;
}