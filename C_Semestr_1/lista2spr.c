#include<stdio.h>
#include<strings.h>
#include<stdlib.h>


struct Node {
  char* data;
  struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, char *new_data) {
  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the data
  new_node->data = new_data;

  new_node->next = (*head_ref);

  // Move head to new node
  (*head_ref) = new_node;
}

void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %s ", node->data);
  node = node->next;
  }
}


int main(){
    struct Node* head = NULL;
    char bufor[2000];
    for (size_t i = 0; i < 10; i++)
    {
        scanf("%s", bufor);
        insertAtBeginning(&head, bufor);
    }
    
    printList(head);
}