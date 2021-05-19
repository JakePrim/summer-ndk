#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/**
 * 结构体就相当于Java中的类的概念
 * @return
 */
struct Dog{
    //定义成员
    char name[10];
    char *n;//可以直接赋值
    int age;
    char sex;
} g1 = {"gs","g",2,'M'},g2={"g3","g",4,'G'},g3;//结尾必须有;结束符号


int mainT2(){
    //使用结构体
    struct Dog dog;//这样写完是没有任务初始化的 成员默认值是系统值(乱码)
    //赋值操作
    //注意数组赋值 需要使用strcpy api函数
    strcpy(dog.name,"旺财");
    dog.age = 3;
    dog.sex = 'G';

    printf("name:%s,age:%d,sex:%c\n",dog.name,dog.age,dog.sex);//name:旺财,age:3,sex:G

    //直接使用
    g3.n = "123";//指针不用使用strcpy 进行赋值
    printf("name:%s,age:%d,sex:%c\n",g1.name,g1.age,g1.sex);//name:gs,age:2,sex:M

    return 0;
}
