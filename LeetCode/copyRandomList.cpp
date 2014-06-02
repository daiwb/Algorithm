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
        if (head == NULL) return head;
        map<RandomListNode*, RandomListNode*> mp;
        RandomListNode* res = new RandomListNode(0);
        RandomListNode* p = head;
        RandomListNode* q = res;
        while (p) {
            RandomListNode* t = new RandomListNode(p->label);
            q->next = t;
            mp[p] = t;
            p = p->next;
            q = q->next;
        }
        p = head;
        q = res->next;
        while (p) {
            if (p->random == NULL) q->random = NULL;
            else q->random = mp[p->random];
            p = p->next;
            q = q->next;
        }
        return res->next;
    }
};