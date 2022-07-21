/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
TC: O(N) - one pass
SC: O(1)
*/
class Solution {
public:
    void addFirst(ListNode* &head, ListNode* &tail, int val){
        ListNode* node = new ListNode(val);
        if(!head){
            head = node;
            tail = node;
            return;
        }
        node->next = head;
        head = node;
    }
    
    void addLast(ListNode* &head, ListNode* &tail, int val){
        ListNode* node = new ListNode(val);
        if(!head){
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        tail = tail->next;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ansLeftHead = NULL;
        ListNode* ansLeftTail = NULL;
        
        ListNode* ansRightHead = NULL;
        ListNode* ansRightTail = NULL;
        
        ListNode* revHead = NULL;
        ListNode* revTail = NULL;
        
        int idx = 1;
        ListNode* temp = head;
        while(temp){
            if(idx < left)
                addLast(ansLeftHead, ansLeftTail, temp->val);
            else if(idx > right)
                addLast(ansRightHead, ansRightTail, temp->val);
            else
                addFirst(revHead, revTail, temp->val);
            idx++;
            
            ListNode* todelete = temp;
            temp = temp->next;
            
            delete todelete;
        }
        
        if(ansLeftTail) ansLeftTail->next = revHead;
        if(ansRightHead) revTail->next = ansRightHead;
        
        if(ansLeftHead) return ansLeftHead;
        return revHead;
    }
};