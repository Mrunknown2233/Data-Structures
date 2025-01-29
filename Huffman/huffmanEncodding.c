#include <stdio.h>
#include <string.h>
#define MAX 100

void mainfunct(char x[], int freq[]) {
    int len = strlen(x), val, i;

    
    for (i = 0; i < len; i++) {
        if (x[i] >= 'A' && x[i] <= 'Z') {
            val = x[i] - 'A';  
            freq[val]++;  
        }
        if (x[i] >= 'a' && x[i] <= 'z') {
            val = x[i] - 'a';
            freq[val]++;  
        }
    }

    
    printf("Letter frequencies:\n");
    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i + 'A', freq[i]);
        }
    }
}

int main() {
    char x[MAX];
    int i, freq[26] = {0};

    
    printf("\nEnter the string: ");
    scanf("%[^\n]s", x);  

    
    mainfunct(x, freq);

    return 0;
}
