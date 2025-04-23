#include <stdio.h>
int main() {
int arr[6] = {94, 45, 72, 32, 51, 60};
int temp;
for (int i = 0; i < 6 - 1; i++) {
for (int j = 0; j < 6 - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
printf("Pass %d: ", i + 1);
for (int k = 0; k < 6; k++) {
printf("%d ", arr[k]);
}
printf("\n");
}
printf("Sorted array: ");
for (int i = 0; i < 6; i++) {
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}