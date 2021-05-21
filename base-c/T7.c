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

    //推荐使用写法
    typedef enum {
        AUDIO = 11,
        INFO,
        VIDEO
    } AVS;

    int mainT7(){
        //clion写法
        enum CommonType commonType = TEXT;
        //VS工具的写法
        //CommonType commonType = TEXT;

        //抹平差异化
        Common common = TEXT;
        Common common2 = TEXT_IMAGE;
        Common common3 = IMAGE;

        printf("common:%d,common2:%d,common3:%d\n",common,common2,common3);//common:10,common2:11,common3:12



        return 0;
    }
