#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Memory allocation failed!\n");
return;
}
newNode->data = value;
newNode->next = NULL;
if (rear == NULL) {
front = rear = newNode;
} else {
rear->next = newNode;
rear = newNode;
}
printf("Inserted: %d\n", value);
}
void dequeue() {
if (front == NULL) {
printf("Queue is Empty!\n");
return;
}
struct Node* temp = front;
front = front->next;
if (front == NULL)
rear = NULL;
printf("Removed: %d\n", temp->data);
free(temp);
}
void display() {
if (front == NULL) {
printf("Queue is Empty!\n");
return;
}
struct Node* temp = front;
printf("Queue elements: ");
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main() {
int choice, value;
do {
printf("\nQueue Operations:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &value);
enqueue(value);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid choice! Please try again.\n");
}
} while (choice != 4);
return 0;
}