// My solution
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL)
            return NULL;
        Node* res = flattenAux(head)[0];
        for(Node* temp = res;temp != NULL;temp = temp->next)
            temp->child = NULL;
        return res;
    }
    
    vector<Node*> flattenAux(Node* head) {
        vector<Node*> res(2, NULL);
        if(head == NULL)
            return res;
        res[0] = head;
        
        vector<Node*> res1 = flattenAux(head->child);
        vector<Node*> res2 = flattenAux(head->next);
        
        if(head->child == NULL)
        {
            if(head->next == NULL)
            {
                res[1] = head;
            }
            else
            {
                res[0]->next = res2[0];
                res2[0]->prev = res[0];
                res[1] = res2[1];                  
            }
        }
        else
        {
            if(head->next == NULL)
            {
                res[0]->next = res1[0];
                res1[0]->prev = res[0];
                res[1] = res1[1];                  
            }
            else
            {
                res[0]->next = res1[0];
                res1[0]->prev = res[0];
                res1[1]->next = res2[0];
                res2[0]->prev = res1[1];
                res[1] = res2[1];     
            }           
        }
        return res;
    }
};

// others solution
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* h = head; h; h = h->next)
        {
            if(h->child)
            {
                Node* p = h->next;
                h->next = h->child;
                h->child = NULL;
                h->next->prev = h;
                Node* p2 = h->next;
                while(p2->next != NULL) p2 = p2->next;
                p2->next = p;
                if(p)
                    p->prev = p2;
            }
        }
        return head;
    }

};