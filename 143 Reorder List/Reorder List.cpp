// O(n^2)
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        
        ListNode* oldhead = head, *newtail = head;
        while(newtail->next->next != NULL)
            newtail = newtail->next;
        

        ListNode* oldtail = newtail->next;
        head = head->next;
        oldhead->next = oldtail;
        oldtail->next = head;
        newtail->next = NULL;
        reorderList(head);   

        return;
    }
};

// O(n)
class Solution {
public:
    void reorderList(ListNode *head) {
        if(!head || !head->next || !head->next->next)
            return;
        
        ListNode* p1 = head, *p2 = head;
        while(p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode* head2 = p1->next;
        p1->next = NULL;
        
        p2 = head2->next;
        head2->next = NULL;
        while(p2)
        {
            p1 = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = p1;
        }
        
        for(p1 = head,p2 = head2;p2;)
        {
            auto t = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = t;
        }
        
    }
};