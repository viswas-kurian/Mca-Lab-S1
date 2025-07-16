#include <stdio.h>

int insert(int a[], int pos, int e) {
    if (pos + 1 == 5) {
        printf("Error: Array is full\n");
    } else {
        a[++pos] = e;
    }
    return pos;
}

int delete(int a[], int pos) {
    if (pos == -1) {
        printf("Error: Array is Empty\n");
    } else {
        printf("\n%d", a[pos--]);
    }
    return pos;
}

void search(int a[], int pos, int se) {
    if (pos == -1) {
        printf("Error: Array is empty\n");
        return;
    }
    int i;
    for (i = 0; i <= pos; i++) {
        if (a[i] == se) {
            printf("Found value %d at position %d\n", se, i);
            return;
        }
    }
    printf("Value %d not found\n", se);
}

void sort(int a[], int pos) {
    int i, j, temp;
    for (i = 0; i <= pos; i++) {
        for (j = 0; j < pos - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Sorted\n");
}

void disp(int a[], int pos) {
    if (pos == -1) {
        printf("Error: Array is empty\n");
        return;
    }
    int i;
    for (i = 0; i <= pos; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int menu() {
    int ch;
    printf("\nINSERT-1\nDELETE-2\nDISP ALL-3\nSearch-4\nSort-5\nEXIT-6\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void processArray() {
    int a[5], pos = -1;
    int ch, se, val;

    for (ch = menu(); ch != 6; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                pos = insert(a, pos, val);
                break;
            case 2:
                pos = delete(a, pos);
                break;
            case 3:
                disp(a, pos);
                break;
            case 4:
                printf("Enter the value to be searched: ");
                scanf("%d", &se);
                search(a, pos, se);
                break;
            case 5:
                sort(a, pos);
                break;
            default:
                printf("Error: Wrong choice\n");
                break;
        }
    }
}

int main() {
    processArray();
    return 0;
}

