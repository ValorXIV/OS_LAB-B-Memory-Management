#include <stdio.h>
#include <stdlib.h>

int global_var_1;
int global_var_2;
int global_var_3;
int global_var_4 = 1;
int global_var_5 = 2;
int global_var_6 = 3;

void stack_test_recursive(int n, int call_count) {
    if(n == 0) {
        return;
    }
    int local_stack_var = 0;
    printf("[Recursion #%d] local stack variable address: %p\n", call_count, &local_stack_var);
    stack_test_recursive(n-1, call_count+1);
}

int main() {
    printf("------ Test Heap Memory Allocation ------\n");
    int *heap_var_1 = (int *)malloc(sizeof(int));
    int *heap_var_2 = (int *)malloc(sizeof(int));
    int *heap_var_3 = (int *)malloc(sizeof(int));
    int *heap_var_4 = (int *)malloc(sizeof(int));
    int *heap_var_5 = (int *)malloc(sizeof(int));
    *heap_var_1 = 1;
    *heap_var_2 = 2;
    *heap_var_3 = 3;
    *heap_var_4 = 4;
    *heap_var_5 = 5; 
    printf("heap variable #1 address: %p\n", heap_var_1);
    printf("heap variable #2 address: %p\n", heap_var_2);
    printf("heap variable #3 address: %p\n", heap_var_3);
    printf("heap variable #4 address: %p\n", heap_var_4);
    printf("heap variable #5 address: %p\n", heap_var_5);
    free(heap_var_1);
    free(heap_var_2);
    free(heap_var_3);
    free(heap_var_4);
    free(heap_var_5);
    printf("------ Test Global Memory Allocation ------\n");
    printf("global variable #1 address: %p\n", &global_var_1);
    printf("global variable #2 address: %p\n", &global_var_2);
    printf("global variable #3 address: %p\n", &global_var_3);
    printf("global variable #4 address: %p\n", &global_var_4);
    printf("global variable #5 address: %p\n", &global_var_5);
    printf("global variable #6 address: %p\n", &global_var_6);
    printf("------ Test Stack Memory Allocation ------\n");
    stack_test_recursive(5, 1);
}