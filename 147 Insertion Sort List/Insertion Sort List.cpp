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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* temp;
        ListNode* turn;
        ListNode* frontturn = head;
        for(turn = head->next;turn != NULL;)
        {
            temp = head;
            if(temp->val > turn->val)
            {
                frontturn->next = turn->next;
                turn->next = head;
                head = turn;
                turn = frontturn->next;
                continue;
            }
            int flag = 0;
            while(temp->next != turn)
            {
                if(temp->next->val > turn->val)
                {
                    frontturn->next = turn->next;
                    turn->next = temp->next;
                    temp->next = turn;
                    turn = frontturn->next;
                    flag = 1;
                    break;
                }
                temp = temp->next;
            }
            if(flag == 0)
            {
                frontturn = frontturn->next;
                turn = turn->next;
            }
        }
        return head;
    }
};