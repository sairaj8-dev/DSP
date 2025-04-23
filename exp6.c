#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int data;
struct node *Next;
} SLL;
SLL *head = NULL;
int create(int x);
void display();
void search();
void insert_begin(int x);
void insert_end(int x);
void insert_after_value(int x, int value);
void delete_begin();
void delete_value(int value);
int main() {
int choice, x, value;
do {
printf("1. Create 2. Display 3. Search 4. Insert at Beginning 5. Insert at End 6. Insert After a
Value 7. Delete from Beginning 8. Exit\n");
printf("Enter the number: ");
scanf("%d", &choice);
switch(choice) {
case 1:
printf("Enter the number: ");
scanf("%d", &x);
create(x);
break;
case 2:
printf("\nSingly Linked List:\n");
display();
break;
case 3:
printf("Enter data to be searched: \n");
search();
break;
case 4:
printf("Enter the number to insert at the beginning: ");
scanf("%d", &x);
insert_begin(x);
break;
case 5:
printf("Enter the number to insert at the end: ");
scanf("%d", &x);
insert_end(x);
break;
case 6:
printf("Enter the value after which to insert: ");
scanf("%d", &value);
printf("Enter the number to insert after %d: ", value);
scanf("%d", &x);
insert_after_value(x, value);
break;
case 7:
delete_begin();
break;
case 8:
break;
default:
printf("Invalid choice\n");
break;
}
} while(choice != 8);
return 0;
}
int create(int x) {
SLL* temp;
if (head == NULL) {
temp = (SLL*)malloc(sizeof(SLL));
temp->data = x;
temp->Next = NULL;
head = temp;
} else {
temp = head;
while (temp->Next != NULL) {
temp = temp->Next;
}
SLL* newNode = (SLL*)malloc(sizeof(SLL));
newNode->data = x;
newNode->Next = NULL;
temp->Next = newNode;
}
return 0;
}
void display() {
if (head == NULL) {
printf("List is empty\n");
} else {
SLL* temp = head;
printf("List: ");
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->Next;
}
printf("\n");
}
}
void search() {
int x;
printf("Enter the number to search: ");
scanf("%d", &x);
int flag = 0;
SLL* temp;
if (head == NULL) {
printf("List is empty\n");
} else {
for (temp = head; temp != NULL; temp = temp->Next) {
if (temp->data == x) {
flag = 1;
break;
}
}
}
if (flag) {
printf("Data %d is found\n", x);
} else {
printf("Data %d not found\n", x);
}
}
void insert_begin(int x) {
SLL* newNode = (SLL*)malloc(sizeof(SLL));
newNode->data = x;
newNode->Next = head;
head = newNode;
}
void insert_end(int x) {
SLL* temp = head;
SLL* newNode = (SLL*)malloc(sizeof(SLL));
newNode->data = x;
newNode->Next = NULL;
if (head == NULL) {
head = newNode;
} else {
while (temp->Next != NULL) {
temp = temp->Next;
}
temp->Next = newNode;
}
}
void insert_after_value(int x, int value) {
SLL* temp = head;
while (temp != NULL) {
if (temp->data == value) {
SLL* newNode = (SLL*)malloc(sizeof(SLL));
newNode->data = x;
newNode->Next = temp->Next;
temp->Next = newNode;
return;
}
temp = temp->Next;
}
printf("Value %d not found in the list.\n", value);
}
void delete_begin() {
if (head == NULL) {
printf("List is empty, nothing to delete.\n");
return;
}
SLL* temp = head;
head = head->Next;
free(temp);
printf("First node deleted.\n");
}