/*
 * File: linked_list.c
 * Author: Manish Jadhav
 * Email: manishsj289@gmail.com
 * Created: September 22, 2023
 * Description: This program implements an LinkedList ADT.
 */

/*
 Implement a LinkedList ADT.
*/

// In this linked list implementation the head points to the node that stores the first element of the linked list
// Create a Linked List ADT using the Struct 'Node'. 
// The Linked List should support all operations that are listed as functions in this file
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// create a LinkedList node with 'data'
struct Node {
    int data;
    struct Node *next;
};

// create a LinkedList node with 'data'
struct Node* create_node(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// pos=-1 indicates insert at end
// pos=0 indicates add at beginning
// This creates a new LinkedList node and inserts it at position 'pos' in the current linked list originating from head
void insert_at_pos(struct Node** head, int data, int pos) {
    if (pos < 0) {
        printf("Invalid position for insertion.\n");
        return;
    }
    struct Node* newNode = create_node(data);
    if (pos == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        int i;
        for (i = 0; i < pos - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Invalid position for insertion.\n");
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// pos=-1 indicates delete last node
// pos=0 indicates delete first node
// This deletes the LinkedList node at position 'pos' in the current linked list originating from head
void delete_at_pos(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    if (pos < 0) {
        printf("Invalid position for deletion.\n");
        return;
    }
    if (pos == 0) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        struct Node* current = *head;
        int i;
        for (i = 0; i < pos - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL || current->next == NULL) {
            printf("Invalid position for deletion.\n");
            return;
        }
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

// delete linkedlist node with first occurrence of given value from linked list originating from 'head'
void delete_by_value(struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Value not found in the list.\n");
}

// gets the node at position 'pos' in linkedlist originating from 'head'
// return 'null' if no node found along with informative message
struct Node* get_node_at_pos(struct Node* head, int pos) {
    if (pos < 0) {
        printf("Invalid position.\n");
        return NULL;
    }
    struct Node* current = head;
    int i;
    for (i = 0; i < pos && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position.\n");
        return NULL;
    }
    return current;
}

// Return the node with the first occurrence of value
// return 'null' if no node found along with informative message
int find_first(struct Node* head, int value) {
    int pos = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1; // Value not found
}

// display entire linked list, starting from head, in a well-formatted way
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// deallocate the memory being used by the entire linkedlist, starting from head
void free_linkedlist(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

// reverse a linkedlist - reverse a given linked list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    struct Node* head = NULL;

    insert_at_pos(&head, 28, 0);
    insert_at_pos(&head, 13, 1);
    insert_at_pos(&head, 9, 1);
    insert_at_pos(&head, 2, 1);
    insert_at_pos(&head, 15, 1);
    insert_at_pos(&head, 7, 1);

    printf("Initial linked list: ");
    display(head);

    delete_at_pos(&head, 1);

    printf("Linked list after deleting node at position 1: ");
    display(head);

    delete_by_value(&head, 20);

    printf("Linked list after deleting node with value 20: ");
    display(head);

    struct Node* node_at_pos = get_node_at_pos(head, 3);
    if (get_node_at_pos != NULL) {
        printf("Node at position 3: %d\n", node_at_pos->data);
    }

    int pos = find_first(head, 9);
    if (pos != -1) {
        printf("First occurrence of 9 is at position: %d\n", pos);
    } else {
        printf("Value 9 not found in the list.\n");
    }

    reverse(&head);

    printf("Reversed linked list: ");
    display(head);

    struct Node* node_at_posi = get_node_at_pos(head, 3);
    if (get_node_at_pos != NULL) {
        printf("Node at position 3: %d\n", node_at_posi->data);
    }

    free_linkedlist(&head);

    return 0;
}
