/*
Name:Prince 
Reg no:PA106/G/28776/25
Description:elements of the array using a nested for loop
*/

#include <stdio.h>

int main() {
int scores[2][2] = {{65, 92}, {84, 72}};
int i, j;

printf("Elements of the array are:\n");
for (i = 0; i < 2; i++) {
for (j = 0; j < 2; j++) {
printf("%d ", scores[i][j]);
}
return 0;
}