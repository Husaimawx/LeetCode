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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* p = root;
        int length = 0;
        while(p != NULL) {
            p = p->next;
            length += 1;
        }
        
        int sl = length / k;
        length = length % k;
        
        p = root;
        vector<ListNode*> res;
        for(int i = 0;i<k;i++) {
            
            int tl = sl;
            if(i < length) {
                tl += 1;    
            }
            
            if(tl == 0) {
                res.push_back(NULL);
            } else {
                ListNode* temp2 = new ListNode(p->val);
                ListNode* temp = temp2;
                for(int i = 1;i<tl;i++) {
                    p = p->next;
                    temp->next = new ListNode(p->val);
                    temp = temp->next;
                }
                p = p->next;
                res.push_back(temp2);
            }
        }
        
        return res;
    }
};