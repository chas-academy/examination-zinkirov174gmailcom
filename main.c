// Write your code in this file
#include <stdio.h>
#include <stdlib.h>

int main() {
int rolls[100];
int counts[6] = {0};
int sum = 0;

srand(1); 

for (int i = 0; i < 100; i++) {
rolls[i] = (rand() % 6) + 1; 
counts[rolls[i] - 1]++; 
sum += rolls[i]; 
}

for (int i = 0; i < 6; i++) {
printf("%d\n", counts[i]);
}

printf("%d\n", sum);
printf("%.1f\n", (float)sum / 100);

return 0;
}
