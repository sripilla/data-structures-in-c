/* Creation of single node in single linked list */
#include<stdio.h>
#include<stdlib.h>

struct node {  
    int data;
    struct node* next;
};

int main() {
  sturct node* head = mallloc(sizeof(struct node));
  head->data = 45;
  head->next = NULL;
  return 0;
}

/* Creation of multiple node(3) in single linked list */

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
  return 0;
  
  
}