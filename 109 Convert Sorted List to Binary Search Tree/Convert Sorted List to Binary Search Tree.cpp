/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *list;
    int count(ListNode *node){
        if(node == NULL)
            return 0;
        int res = 1;
        while(node->next != NULL)
        {
            res++;
            node = node->next;
        }
        return res;
    }
    
    TreeNode *generate(int n){
        if(n == 0)
            return NULL;
        TreeNode* head = new TreeNode(0);
        head->left = generate(n/2);
        head->val = list->val;
        list = list->next;
        head->right = generate(n-n/2-1);
        return head;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        this->list = head;
        return generate(count(head));
    }
};