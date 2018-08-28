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
        if(l1->val == 0)
            return l2;
        if(l2->val == 0)
            return l1;
        
        vector<int> num1(1,0);
        vector<int> num2(1,0);
        ListNode* p;
        for(p = l1;p;p = p->next)
        {
            num1.push_back(p->val);
        }
        for(p = l2;p;p = p->next)
        {
            num2.push_back(p->val);
        }
        
        int carry = 0;
        
        if(num1.size() >= num2.size())
        {
            num2.insert(num2.begin(),num1.size()-num2.size(),0);
        }
        else
            num1.insert(num1.begin(),num2.size()-num1.size(),0);
        
        int to = num1.size()-1;
        while(to >= 0)
        {
            num1[to] += (num2[to]+carry);
            if(num1[to] > 9)
            {
                num1[to]-=10;
                carry = 1;
            }
            else
                carry = 0;
            to--;
        } 
        
        to = 0;
        while(num1[to] == 0) to++;
        ListNode* res;
        p = new ListNode(0);
        res = p;
        for(int from = to;from < num1.size();from++)
        {
            p->next = new ListNode(num1[from]);
            p = p->next;
        }
        p->next = NULL;
        return res->next;
    }
};