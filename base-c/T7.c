//
// Created by sufulu on 2021/5/19.
//
#include <stdio.h>
//枚举 int类型的
enum CommonType{
    TEXT = 10,//不给值默认是从0开始
    TEXT_IMAGE,
    IMAGE
};

//定义别名 抹平不同工具的差异化
typedef enum CommonType Common;

int main(){
    //clion写法
    enum CommonType commonType = TEXT;
    //VS工具的写法
    //CommonType commonType = TEXT;

    //抹平差异化
    Common common = TEXT;
    Common common2 = TEXT_IMAGE;
    Common common3 = IMAGE;



    return 0;
}
