/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // My Solution
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *p,*p1,*p2;
        p = head;
        if(head == NULL)
            return NULL;
        
        p1 = NULL;
        p2 = NULL;
        if(p->val < x)
        {
            p1 = p;
            p = p->next;
            while(p!=NULL && p->val < x)
            {
                p1 = p;
                p = p->next;
            }
            if(p == NULL)
                return head;
            p2 = p;
            p = p->next;
        }
        else
        {
            p2 = p;
            p = p->next;
            while(p!=NULL && p->val >= x)
            {
                p2 = p;
                p = p->next;
            }
            if(p == NULL)
                return head;
            p1 = p;
            p2->next = p->next;
            p1->next = head;
            head = p1;
            p = p2->next;
        }
        
        while(p!=NULL)
        {
            if(p->val < x)
            {
                p2->next = p->next;
                p->next = p1->next;
                p1->next = p;
                p1 = p;
                p = p2->next;
            }
            else
            {
                p2 = p;
                p = p->next;
            }
        }
        
        return head;
    }
};

// Other people's solution
ListNode *partition(ListNode *head, int x) {
    ListNode node1(0), node2(0);
    ListNode *p1 = &node1, *p2 = &node2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = node2.next;
    return node1.next;
}