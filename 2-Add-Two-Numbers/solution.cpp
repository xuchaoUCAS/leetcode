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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode fake(0), *p = &fake;
        int add = 0;
        while(l1 || l2 || add){
            int temp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + add;
            add = temp / 10;
            ListNode *node = new ListNode(temp % 10);
            p->next = node;
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return fake.next;
    }
};