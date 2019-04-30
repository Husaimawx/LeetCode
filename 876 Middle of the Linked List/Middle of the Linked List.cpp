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
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* p = head;
        while(p != NULL) {
            length += 1;
            p = p->next;
        }
        
        cout << length;
        length = length/2;
        p = head;
        for(int i = 0;i<length;i++) {
            p = p->next;
        }
        
        return p;
    }
};