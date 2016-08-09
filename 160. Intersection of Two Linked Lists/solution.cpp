/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define NULL nullptr
#include <set>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
typedef struct ListNode ListNode;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> s;
        ListNode *left;
        while (headA != NULL || headB != NULL) {
            if (headA != NULL) {
                if (s.count(headA)) return headA;
                s.insert(headA);
                headA = headA->next;
                left = headA;
            }
            if (headB != NULL) {
                if (s.count(headB)) return headB;
                s.insert(headB);
                headB = headB->next;
                left = headB;
            }
        }
        while (left != NULL) {
            if (s.count(left)) return left;
            s.insert(left);
            left = left->next;
        }
        return NULL;
    }
};

// best solution
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (ptrA != ptrB) {
            if (ptrA == NULL)
                ptrA = headB;
            else ptrA = ptrA->next;
            if (ptrB == NULL)
                ptrB = headA;
            else ptrB = ptrB->next;
        }
        return ptrA;
    }
    
};


int main(int argc, char const *argv[])
{
    ListNode *headA = new ListNode(1);
    ListNode *headB = NULL;
    std::cout << Solution().getIntersectionNode(headA, headB) << std::endl;
    return 0;
}