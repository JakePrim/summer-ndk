//
// Created by sufulu on 2021/5/19.
// 结构体指针
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
struct Cat{
    char name[10];
    int age;
};
int mainT4(){
    //栈区
    //声明结构体
    struct Cat cat = {"猫马上",2};
    //结构体指针
    //vs的写法：Cat *catp = &cat;
    struct Cat * catp = &cat;
    //-> 调用一级指针成员
    catp->age = 18;
    strcpy(catp->name,"毛毛");
    printf("name:%s,age:%d\n",catp->name,catp->age);


    //堆区 动态开辟
    //申请空间
    struct Cat *c1 = (struct Cat *)malloc(sizeof(struct Cat));
    strcpy(c1->name,"213");
    c1->age = 19;
    printf("name:%s,age:%d\n",c1->name,c1->age);
    //释放空间
    free(c1);
    c1 = NULL;


    return 0;
}

