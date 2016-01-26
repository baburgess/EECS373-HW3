#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
    assert(head != NULL);
    assert(new_element != NULL);
    
    //find place to insert new_element.
    list_t* head_save = head;
    while((head->next != NULL) && (head->next->index < new_element->index))
    {
        head = head->next;
    }
    
    //if the new element is less than the head put it behind the head
    if(new_element->index < head->index)
    {
        head_save = new_element;
        new_element->next = head;
    }
    //insert the new_element after the head
    else
    {
        list_t* after_new = head->next;
        head->next = new_element;
        new_element->next = after_new;
    }    
    return head_save;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
    assert(head != NULL);
    
    list_t* next_el;
    list_t* prev_el = NULL;
    do
    {
        next_el = head->next;
        head->next = prev_el;
        prev_el = head;
        head = next_el;
    } while(head != NULL);
    
    return prev_el;
}

