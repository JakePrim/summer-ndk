#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Hello, World!\n");

    //申请堆空间
    int *arr = (int *)malloc(sizeof(int)*4);

    //扩展堆空间大小
    int *new_arr = realloc(arr, sizeof(arr) * 2);

    //释放堆空间
    if (new_arr){
        free(new_arr);
        new_arr = NULL;
        arr = NULL;
    }else{
        //假如 realloc 失败了
        free(arr);
        arr = NULL;
    }

    return 0;
}
