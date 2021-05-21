//
// Created by sufulu on 2021/5/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Cat3{
    char name[10];
    int age;
};
int mainT5(){
    //结构体数组
    struct Cat3 cat3[10]={
            {"xs",1},
            {"xs2",2},
            {"xs3",3},
    };

    struct Cat3 tc9 = {"s9",9};
//    cat3[9] = tc9;
    //指针 和上面是等价 的
    *(cat3 + 9) = tc9;
    printf("name:%s,age:%d\n",cat3[9].name,cat3[9].age);

    //动态开辟
    struct Cat3 *cat2 = malloc(sizeof(struct Cat3) * 10);//开辟10个Cat3的空间大小 和上面的数组[10]是一样的

    //赋值操作 cat2默认指向首元素地址
    strcpy(cat2->name,"12321");
    cat2->age = 10;
    printf("name:%s,age:%d\n",cat2->name,cat2->age);//name:12321,age:10

    //给第二个元素赋值
    struct Cat3 *temp = cat2;
    temp+=1;
    strcpy(temp->name,"2222");
    temp->age = 11;
    printf("name:%s,age:%d\n",temp->name,temp->age);//name:2222,age:11

    printf("cat:%p\n",cat2);//006B58F8
    printf("temp:%p\n",temp);//006B58F8
    //注意在释放时需要回到首元素 因此尽量不去改动cat2的指向而是通过temp
    free(cat2);
    cat2 = NULL;
    printf("cat free之后\n");
    printf("cat:%p\n",cat2);//00000000
    printf("temp:%p\n",temp);//006B58F8 注意temp成了悬空指针 需要置为NULL
    temp = NULL;

    return 0;
}
