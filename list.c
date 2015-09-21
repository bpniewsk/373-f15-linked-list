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
        
        struct list_t *prev = NULL;
        struct list_t *current = head;
        int prev_ind = 0;
	int cur_ind = 0;
 	int new = new_element->index; 

        while(1){ 
                if(prev != NULL){
			prev_ind = prev->index;
		} 
 		cur_ind = current->index; 	
	        if(head == current){ 
                	if(new <= cur_ind){ 
				head = new_element; 
               			head->next = current;
                                return head;						 
 			}
 			else if(head->next == NULL){
				head->next = new_element;
                                new_element->next = NULL;
                                return head;	
			}
                        else{
                         	prev = head;
				current = head->next;
  				continue; 
			}
		}	
		else if(new <= cur_ind){
 			prev->next = new_element;
			new_element->next = current;
			return head;
		}
                else if(current->next == NULL){
               		current->next = new_element; 
 			new_element->next = NULL;
         		return head; 
		}
		else{ 
			prev = current; 
                        current = current->next;
			continue;
		}	
	}
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

        struct list_t *prev = head;
        struct list_t *current = head->next;
        if(current == NULL){ 
		return head;
	}
	else{
		struct list_t *next = current->next;
		prev->next = NULL;         	
		while(1){ 
			current->next = prev;
			if(next == NULL){ 
				head = current;
				return head;	
			}
		prev = current;
        	current = next; 
		next = next->next;
 		}			
	}
}

