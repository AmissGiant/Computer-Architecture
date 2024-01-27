#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node* next;
    int data;
};//no clue why this is needed
struct Node* head = NULL;
int length;
void delete(int n){//deleted a node
    if(head == NULL){
        return;
    }
    if(head->data == n){
        struct Node* temp = head;
        head = head->next;
        free(temp);
        length--;
    }else{
        struct Node* current = head;
        while(current->next != NULL && current->next->data != n){
            current = current->next;
        }
        if(current->next != NULL){
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            length--;
        }
        }
}
void insert(int n){//inserts a node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));//create space for newNode
    newNode->data = n;
    newNode->next  = NULL;
    if(head == NULL || n < head->data){
        newNode->next = head;
        head = newNode;
        length++;
    }else if(n != head->data){
        struct Node* current = head;
        while(current->next != NULL && current->next->data < n){
            current = current->next;
        }
        if(current->next == NULL || n != current->next->data){
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }else{
    free(newNode);//no longer need space for newNode
    }
}else{
    free(newNode);//adding this one got rid og my issue with test 02, idk why tho
}
}
void printList(){//don't need anyhting because it prints entire list at once
    struct Node* current = head;
    printf("%d :", length);//only printing ints
        while(current != NULL){
            printf(" %d", current->data);
            current = current->next;
    }
    printf("\n");
}
int main(){//confused why I don't need argc and argv but it gave error 1
    char action;
    int n;
    while(scanf(" %c %d", &action, &n) == 2){// reading char frirst, then int from input file
        if(action == 'i'){//inserts
            insert(n);
        }else if(action == 'd'){//deleted
            delete(n);
        }
        printList();
    }
    while(head != NULL){
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}