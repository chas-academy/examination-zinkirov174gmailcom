// Write your code in this file
 #include <stdio.h>
#include <stdlib.h>

#define ROLL() ((rand() % 6) + 1)

int main() {
int counts[6] = {0}, sum = 0;

srand(1);

for (int i = 0; i < 100; i++) {
int roll = ROLL();
counts[roll - 1]++;
sum += roll;
}

for (int i = 0; i < 6; i++) {
printf("%d\n", counts[i]);
}

printf("%d\n", sum);
printf("%.1f\n", (float)sum / 100);

return 0;
}
