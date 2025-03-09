#include "llrec.h"
#include <iostream>
using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
    if(head == nullptr){
        larger = nullptr;
        smaller = nullptr;
        head = nullptr;
        return;
    }
    llpivot(head->next, smaller, larger, pivot);

    if(head->val > pivot){
        head->next = larger;
        larger = head;
        head = nullptr;
    }
    else{
        head->next = smaller;
        smaller = head;
        head = nullptr;
    }

}
