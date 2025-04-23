#include <stdio.h>
#include <stdlib.h>
typedef struct stack {
int data;
struct stack *next;
}ST_node;
ST_node *top=NULL, *temp;
int push(int x);
int pop();
void display();
int main() {
int choice, x;
do {
printf("1. push\t 2. pop\t 3. display\t 4. exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
printf("Enter the data to be pushed: ");
scanf("%d", &x);
push(x);
break;
case 2:
x = pop();
if (x != -1) {
printf("Popped data is %d\n", x);
}
break;
case 3:
display();
break;
case 4:
break;
default:
printf("Invalid choice\n");
}
} while(choice != 4);
return 0;
}
int push(int x)
{
ST_node*New_node=(ST_node*)malloc(sizeof(ST_node));
if(New_node==NULL){
printf("Memory allocation failed!\n");
return -1;
}
New_node->data=x;
New_node->next=top;
top=New_node;
return 0;
}
int pop() {
if (top == NULL) {
printf("Stack is empty\n");
return -1;
}
temp = top;
top = top->next;
int x = temp->data;
free(temp);
return x;
}
void display() {
if (top == NULL) {
printf("Stack is empty\n");
} else {
printf("Stack elements are:\n");
for(temp = top; temp != NULL; temp=temp->next)
printf("%d\n", temp->data);
temp = temp->next;
}
}