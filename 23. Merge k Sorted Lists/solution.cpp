/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct {
        bool operator()(const ListNode* a, const ListNode *b) {
            return a->val > b->val;
        }
    } cmp;

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto &l: lists) {
            if (l) pq.push(l);
        }
        if (pq.empty()) return nullptr;
        while (!pq.empty()) {
            cur = cur->next = pq.top();
            pq.pop();
            if (cur->next) pq.push(cur->next);
        }
        return dummy.next;
    }
};

class Soltuion {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        for (auto &l: lists) {
            cur->next = l;
            while (cur->next != nullptr)
                cur = cur->next;
        }
        std::sort(dummy.next, [](const ListNode *a, const ListNode *b) -> bool {
            return a->val < b->val;
        });
        return res;
    }
};