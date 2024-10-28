/* Traversing a single linked list  (count_of_nodes) */

#include<stdio.h>
#include<stdlib.h>

struct node {  
    int data;
    struct node* next;
};

int main() {
  sturct node* head = mallloc(sizeof(struct node));
  head->data = 45;
  head->link = NULL;

  struct node* current = malloc(sizeof(struct node));
  current->data = 98;
  current->link = NULL;
  head->link = current;

  struct node* current2 = malloc(sizeof(struct node));
  current2->data = 3;
  current2->link = NULL;
  current->link = current2;   /* head->link->link = current2 */

  count_of_nodes(head);
  return 0;
}

void count_of_nodes(struct node* head) {
  int count = 0;
  if(head == NULL) 
    printf("Linked list is empty.");
  struct node* ptr = NULL;
  ptr = head;
  while(ptr != NULL) {
    count++;
    ptr = ptr->next;
  }
  printf("Number of nodes in the linked list: %d", count);
}
