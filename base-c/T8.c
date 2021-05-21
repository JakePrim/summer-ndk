#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    //文件操作
    //参数一：_Filename 文件的来源
    //参数二：_Mode 模式r(读) w(写)  rb(作为二进制文件的读) wb(作为二进制文件的写)
    //返回值：FILE 结构体
//    fopen();
    printf("读取文件\n");

    char *fileName = "D:\\ee.txt";//文件的路径
    FILE * file = fopen(fileName,"r");
    if(!file){
        //如果file为null就表示读取失败了
        printf("文件打开失败");
        exit(0);//退出程序
    }
    printf("读取文件成功\n");
    //读取文件的内容，先定义缓冲区
    char buffer[10];
    //fgets:1:缓冲区 2：长度10 3 ：文件
    while (fgets(buffer,10,file)){
        printf("%s",buffer);
    }

    //关闭文件
    fclose(file);

    //文件的写操作
    char *fileName2 = "D:\\ee2.txt";//文件的路径
    FILE * wfile = fopen(fileName2,"w");
    if(!wfile){
        printf("打开文件失败");
        exit(0);
    }
    fputs("写入文件",wfile);

    //关闭文件
    fclose(wfile);

    return 0;
}