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

// a more interesting and space free solution
public RandomListNode copyRandomList(RandomListNode head) {
	RandomListNode iter = head, next;

	// First round: make copy of each node,
	// and link them together side-by-side in a single list.
	while (iter != null) {
		next = iter.next;

		RandomListNode copy = new RandomListNode(iter.label);
		iter.next = copy;
		copy.next = next;

		iter = next;
	}

	// Second round: assign random pointers for the copy nodes.
	iter = head;
	while (iter != null) {
		if (iter.random != null) {
			iter.next.random = iter.random.next;
		}
		iter = iter.next.next;
	}

	// Third round: restore the original list, and extract the copy list.
	iter = head;
	RandomListNode pseudoHead = new RandomListNode(0);
	RandomListNode copy, copyIter = pseudoHead;

	while (iter != null) {
		next = iter.next.next;

		// extract the copy
		copy = iter.next;
		copyIter.next = copy;
		copyIter = copy;

		// restore the original list
		iter.next = next;

		iter = next;
	}

	return pseudoHead.next;
}