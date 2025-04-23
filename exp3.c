#include <stdio.h>
void concatenateStrings(char* dest, const char* src) {
while (*dest) dest++;
while (*src) *dest++ = *src++;
*dest = '\0';
}
int compareStrings(const char* str1, const char* str2) {
while (*str1 && (*str1 == *str2)) { str1++; str2++; }
return (unsigned char)*str1 - (unsigned char)*str2;
}
int stringLength(const char* str) {
int len = 0;
while (*str++) len++;
return len;
}
void reverseString(char* str) {
int start = 0, end = stringLength(str) - 1;
while (start < end) {
char temp = str[start];
str[start++] = str[end];
str[end--] = temp;
}
}
int main() {
char str1[100], str2[100];
prinƞ("Enter first string: ");
fgets(str1, 100, stdin);
str1[strcspn(str1, "\n")] = '\0';
prinƞ("Enter second string: ");
fgets(str2, 100, stdin);
str2[strcspn(str2, "\n")] = '\0';
char concat[200];
strcpy(concat, str1);
concatenateStrings(concat, str2);
prinƞ("Concatenated: %s\n", concat);
int cmp = compareStrings(str1, str2);
prinƞ("Comparison: %s\n", cmp == 0 ? "Equal" : (cmp < 0 ? "Less" : "Greater"));
prinƞ("Length of first string: %d\n", stringLength(str1));
reverseString(str1);
prinƞ("Reversed first string: %s\n", str1);
return 0;
}