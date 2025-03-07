#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
    if(head == nullptr){
        return;
    }
    llpivot(head->next, smaller, larger, pivot);
    if(head->val > pivot){
        if(head->next = nullptr){
            head->next = nullptr;
        }
        else{
            head->next = larger;
        }
        
        larger = head;
    }
    else{
        if(head->next = nullptr){
            head->next = nullptr;
        }
        else{
            head->next = smaller;
        }
        smaller = head;
    }

}
