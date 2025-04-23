#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* left;
struct Node* right;
};
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
struct Node* insert(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else {
root->right = insert(root->right, value);
}
return root;
}
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
void preorder(struct Node* root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}
void postorder(struct Node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}
int main() {
struct Node* root = NULL;
root = insert(root, 50);
insert(root, 70);
insert(root, 60);
insert(root, 20);
insert(root, 90);
insert(root, 10);
insert(root, 40);
insert(root, 100);
printf("Inorder Traversal: ");
inorder(root);
printf("\n");
printf("Preorder Traversal: ");
preorder(root);
printf("\n");
printf("Postorder Traversal: ");
postorder(root);
printf("\n");
return 0;
}