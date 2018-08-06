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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* tempA = headA;
        int lenA = 1;
        while(tempA->next != NULL)
        {
            tempA = tempA->next;
            lenA++;
        }
        
        ListNode* tempB = headB;
        int lenB = 1;
        while(tempB->next != NULL)
        {
            tempB = tempB->next;
            lenB++;
        }
        
        if(tempA != tempB)
        {
            return NULL;
        }
        
        tempA = headA;
        tempB = headB;
        if(lenA > lenB)
        {
            for(int i = 0;i<lenA-lenB;i++)
            {
                tempA = tempA->next;
            }
        }
        else if(lenA < lenB)
        {
            for(int i = 0;i<lenB-lenA;i++)
            {
                tempB = tempB->next;
            }            
        }
        
        while(tempA != tempB)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return tempA;
    }
};