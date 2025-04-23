#include <stdio.h>
#define MAX 10
typedef struct Q {
int R, F;
int data[MAX];
} Q;
int empty(Q *P);
int full(Q *P);
void enqueue(Q *P, int x);
int dequeue(Q *P);
void BFS(int v);
void DFS(int v);
int G[MAX][MAX];
int n = 0;
int visited[MAX];
void main() {
int i, j, v, op;
printf("\nEnter number of vertices: ");
scanf("%d", &n);
printf("\nEnter the adjacency matrix of the graph:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &G[i][j]);
}
}
do {
printf("\n\n1) DFS\n2) BFS\n3) QUIT");
printf("\nEnter your choice: ");
scanf("%d", &op);
switch (op) {
case 1:
printf("\nEnter the starting vertex for DFS: ");
scanf("%d", &v);
for (i = 0; i < n; i++) visited[i] = 0;
DFS(v);
break;
case 2:
printf("\nEnter the starting vertex for BFS: ");
scanf("%d", &v);
for (i = 0; i < n; i++) visited[i] = 0;
BFS(v);
break;
}
} while (op != 3);
}
void BFS(int v) {
int i;
Q q;
q.R = q.F = -1;
for (i = 0; i < n; i++) visited[i] = 0;
enqueue(&q, v);
visited[v] = 1;
printf("\nVisited: %d", v);
while (!empty(&q)) {
v = dequeue(&q);
for (i = 0; i < n; i++) {
if (visited[i] == 0 && G[v][i] != 0) {
enqueue(&q, i);
visited[i] = 1;
printf("\nVisited: %d", i);
}
}
}
}
int empty(Q *P) {
return P->R == -1;
}
int full(Q *P) {
return P->R == MAX - 1;
}
void enqueue(Q *P, int x) {
if (P->R == -1) {
P->R = P->F = 0;
P->data[P->R] = x;
} else {
P->R = P->R + 1;
P->data[P->R] = x;
}
}
int dequeue(Q *P) {
int x = P->data[P->F];
if (P->R == P->F) {
P->R = -1;
P->F = -1;
} else {
P->F = P->F + 1;
}
return x;
}
void DFS(int i) {
int j;
printf("\nVisited: %d", i);
visited[i] = 1;
for (j = 0; j < n; j++) {
if (!visited[j] && G[i][j] == 1) {
DFS(j);
}
}
}