#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

//
struct Study{
    char *studyContent;//学习内容
};
//结构体嵌套
struct Student{
    char name[10];
    int age;
    char sex;
    struct Study study;//Clion工具的写法
//    Study st;vs的写法
    struct Wan{
        char * wanContent;
    } wan;//定义结构体别名
};

int mainT3(){
    //使用结构体
    struct Student student = {"丽丽",18,'N',
            {"学习C语言"},
            {"游戏"}
    };
    //获取嵌套的结构体
    student.study.studyContent;
    student.wan.wanContent;
    printf("姓名：%s",student.name);
    return 0;
}