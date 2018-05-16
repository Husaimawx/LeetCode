/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *node, *node2 = NULL;
        map<int, RandomListNode*> nodesMap;
        for(node = head;node!=NULL;node = node->next)
        {
            node2 = new RandomListNode(node->label);
            nodesMap[node->label] = node2;
        }
        
        RandomListNode *res;
        for(node = head;node!=NULL;node = node->next)
        {
            node2 = nodesMap[node->label];
            if(node == head)
                res = node2;
            
            if(node->next == NULL)
                node2->next = NULL;
            else
                node2->next = nodesMap[node->next->label];
            
            if(node->random == NULL)
                node2->random = NULL;
            else
                node2->random = nodesMap[node->random->label];
        }
        
        return res;
    }
};