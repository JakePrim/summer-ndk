#include <stdio.h>
#include <stdlib.h>

//在学习结构体的时候会发现在VS 和 Clion平台的写法不一致那么如何避免这种问题呢？
//定义结构体类型
struct Worker_{
    char *name;
    int age;
    char sex;
};
//VS 的写法typedef Worker_
//定义typedef 可以兼容代码写法
typedef struct Worker_ Worker_;//给结构体取别名

typedef struct Worker_ * Worker;//给结构体指针取别名

//匿名结构体的别名 推荐使用给结构体取了别名 = AV
typedef struct {
    char *name;
    int age;
    char sex;
} AV;

//在方法中使用结构体
void show(AV* a){

}



int mainT6(){
    //两种平台的写法就会一致
    Worker worker = malloc(sizeof(Worker_));

    //不用考虑差异化
    AV * av = malloc(sizeof(AV));

    AV a = {"测试",123,'N'};

    return 0;
}
