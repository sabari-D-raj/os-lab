#include <stdio.h>

int main() {
    int page[50], frame[50];
    int n, f, i, j, found, fault = 0, next = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page references: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) {
        frame[i] = -1;
    }
    printf("\nPage\t");
    for(i = 0; i < f; i++) {
        printf("Frame%d\t", i + 1);
    }
    printf("Status\n");
    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            frame[next] = page[i];
            next = (next + 1) % f;
            fault++;
        }
        printf("%d\t", page[i]);
        for(j = 0; j < f; j++) {
            if(frame[j] == -1)
                printf("-\t");
            else
                printf("%d\t", frame[j]);
        }
        if(found)
            printf("Hit");
        else
            printf("Fault");
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", fault);
    return 0;
}
