
#include <stdio.h>
int main() {
int rows, cols;
prinƞ("Enter the number of rows and columns: ");
scanf("%d %d", &rows, &cols);
int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols]
prinƞ("Enter elements for matrix1:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
scanf("%d", &matrix1[i][j]);
}
}
prinƞ("Enter elements for matrix2:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
scanf("%d", &matrix2[i][j]);
}
}
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
result[i][j] = matrix1[i][j] + matrix2[i][j];
}
}
prinƞ("ResulƟng matrix:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
prinƞ("%d ", result[i][j]);
}
prinƞ("\n");
}
return 0;
}