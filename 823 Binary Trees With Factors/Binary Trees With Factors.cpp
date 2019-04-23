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
        ListNode* ans = new ListNode(0);
        ListNode* p = ans;
        int firstTime = 1;
        
        int upgrade = 0;
        int temp1 = 0;
        int temp2 = 0;
        while(l1 != NULL || l2 != NULL)
        {
            if(firstTime == 0)
            {
                ans->next = new ListNode(0);
                ans = ans->next;   
            }
            else
                firstTime = 0;
            
            if(l1 == NULL)
                temp1 = 0;
            else
            {
                temp1 = l1->val;
                l1 = l1->next;
            }
            if(l2 == NULL)
                temp2 = 0;
            else
            {
                temp2 = l2->val;
                l2 = l2->next;
            }
            ans->val = temp1 + temp2 + upgrade;
            if(ans->val > 9)
            {
                upgrade = 1;
                ans->val -= 10;
            }
            else
            {
                upgrade = 0;
            }
        }
        if(upgrade == 0)
            return p;
        else
        {
            ans->next = new ListNode(1);
            return p;    
        }
    }
};