#include <stdio.h>
#include <stdlib.h>

int indexOf(int* arr, int target, int from, int to) {
    if (to == -1)
        to = sizeof(arr) / sizeof(arr[0]);

    int size = abs(from - to);
    printf("%d\n", size);


    if (arr[size/2] == target)
        return 0;
    else {
        if (arr[size/2] < target)
            return from + indexOf(arr, target, from + size/2 + 1, to);
        else
            return to - indexOf(arr, target, from, to/2);
    }
}

int main() {
    int arr[8] = { 11, 42, 58, 73, 120, 666, 729, 730 };

    int target;

    printf("Digite o valor que deseja encontrar: ");
    scanf("%d", &target);

    int index = indexOf(arr, target, 0, -1);

    if (index == -1)
        printf("No matching element!\n");
    else
        printf("Index is %d\n", index);

    return 0;
}
