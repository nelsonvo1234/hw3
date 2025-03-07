#include "llrec.h"
#include <iostream>
using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
    if(head == nullptr){
        return;
    }
    llpivot(head->next, smaller, larger, pivot);
    if(head->next == nullptr){
        larger = nullptr;
        smaller = nullptr;
    }
    if(head->val > pivot){

        head->next = larger;
        larger = head;
    }
    else{
        head->next = smaller;
        smaller = head;
    }

}
