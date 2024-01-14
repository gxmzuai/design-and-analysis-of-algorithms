#include <stdio.h>
#include <string.h>

void removeDigits(char *n, int s) {
    int len = strlen(n), i, j;
    for (i = 0; i < s; i++) {
        int len = strlen(n);
        for (j = 0; j < len - 1; j++) {
            if (n[j] > n[j + 1]) {
                break;
            }
        }
        memmove(&n[j], &n[j + 1], len - j);
    }
}

int main() {
    char n[100];
    int s;
    printf("Enter the number: ");
    scanf("%s", n);
    printf("Enter the number of digits to remove: ");
    scanf("%d", &s);
    removeDigits(n, s);
    printf("Result: %s\n", n);
    return 0;
}
