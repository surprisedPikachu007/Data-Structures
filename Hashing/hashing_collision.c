#include <stdio.h>
#include <stdlib.h>

int size;

int hash(int key) {
    return key % size;
}

int linear_probing(int key){
    return (key+1) % size;
}

int quadratic_probing(int key, int i){
    return (key + i*i) % size;
}

int double_probing(int key, int i){
    return (key + i*(i+1)/2) % size;
}

int main() {
    int i, j;
    int key;
    int *hash_table_linear, *hash_table_quadratic, *arr;

    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    hash_table_linear = (int *) malloc(size * sizeof(int));
    hash_table_quadratic = (int *) malloc(size * sizeof(int));
    arr = (int *) malloc(size * sizeof(int));

    for (i = 0; i < size; i++){
        hash_table_linear[i] = -1;
        hash_table_quadratic[i] = -1;
    }

    printf("Enter the keys: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &key);
        arr[i] = key;
    }

    for(i=0; i<size; i++){
        j = hash(arr[i]);
        while(hash_table_linear[j] != -1){
            j = linear_probing(j);
        }
        hash_table_linear[j] = arr[i];
    }

    for(i=0; i<size; i++){
        j = hash(arr[i]);
        while(hash_table_quadratic[j] != -1){
            j = quadratic_probing(arr[i], j);
        }
        hash_table_quadratic[j] = arr[i];
    }


    printf("\nThe hash table with linear probing is: \n");
    for (i = 0; i < size; i++) {
        printf("%d |%d|\n", i+1, hash_table_linear[i]);
    }

    printf("\nThe hash table with quadratic probing is: \n");
    for (i=0; i<size; i++){
        printf("%d |%d|\n", i+1, hash_table_quadratic[i]);
    }

    printf("\n");

    return 0;
}