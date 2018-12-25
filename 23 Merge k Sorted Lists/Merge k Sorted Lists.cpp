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
    struct data {
        int num;
        int from;
        
        bool operator<(const data& a) const
        {
            return num > a.num; //大顶堆
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<data> Q;
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        
        for(int i = 0;i<lists.size();i++) {
            if(lists[i] != NULL) {
                data temp = {lists[i]->val,i};
                Q.push(temp);
            }
        }   
        
        while(!Q.empty()) {         
            data temp = Q.top();
            p->next = new ListNode(temp.num);
            p = p->next;
            lists[temp.from] = lists[temp.from]->next;
            Q.pop();
            if(lists[temp.from]!=NULL) {
                data newadd = {lists[temp.from]->val,temp.from};
                Q.push(newadd);
            }
        }
        return head->next;
    }
};