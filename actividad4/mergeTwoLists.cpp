
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * i1 = l1; 
        ListNode * i2 = l2; 
        ListNode * head = NULL;
        ListNode * iterator = NULL;
        while(i1 && i2){ 
            if(i1->val < i2->val){ 
                if(head == NULL){ 
                    head = i1; 
                    i1 = i1->next;
                    iterator = head;
                }  
                else{
                    iterator->next = i1; 
                    i1 = i1->next; 
                    iterator = iterator->next;
                }
                    
            }else { 
                if(head == NULL){ 
                    head =i2; 
                    i2 = i2->next;
                    iterator = head;
                } 
                else{
                    iterator->next = i2; 
                    i2 = i2->next; 
                    iterator = iterator->next; 
                }
                
            }
        } 
        while(i1){
            if(head == NULL){ 
                    head = i1; 
                    i1 = i1->next;
                    iterator = head;
                }  
                else{
                    iterator->next = i1; 
                    i1 = i1->next; 
                    iterator = iterator->next;
                }
                
        } 
        while(i2){
            if(head == NULL){ 
                    head =i2; 
                    i2 = i2->next;
                    iterator = head;
                } 
                else{
                    iterator->next = i2; 
                    i2 = i2->next; 
                    iterator = iterator->next; 
                }
        }
        return head; 
    }

};
        