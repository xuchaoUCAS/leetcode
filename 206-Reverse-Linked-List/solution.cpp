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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* node = head;
        while(node){
            ListNode* temp = node->next;
            node->next = pre;
            pre = node;
            node = temp;
        }
        return pre;
    }
};