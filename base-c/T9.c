#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//文件的复制 二进制文件来复制
int main(){
    char *fileName = "D:\\ee.txt";//copy的来源
    char *fileName2 = "D:\\ee2.txt";//copy的目标

    FILE * file = fopen(fileName,"rb");//二进制读取
    FILE * wfile = fopen(fileName2,"wb");//二进制写入
    if(!file || !wfile){
        printf("文件打开失败");
        exit(0);
    }
    //获取文件的大小
    //移动头指针到文件的末尾
    //SEEK_CUR 代表是当前的位置
    //SEEK_SET 代表是开头的位置
    //SEEK_END 代表是结尾的位置
    fseek(file,SEEK_SET,SEEK_END);
    //会给file指针赋值，挪动的记录
    long file_size = ftell(file);//读取刚刚给file记录的信息
    printf("%s,文件的大小:%ld\n",fileName,file_size);//D:\ee.txt,文件的大小:16

    int buffer[512];//512 * 4 = 2048个字节
    int len;//每次读取的长度
    //读取目标文件操作:
    //参数1：读取到容器中去
    //参数2：每次偏移多少
    //参数3：容器大小 不要直接写数字：sizeof(buffer)/ sizeof(int) = 512
    //参数4：目标文件
    while ((len= fread(buffer, sizeof(int), sizeof(buffer)/ sizeof(int),file))!=0){
        //写入到目标文件
        fwrite(buffer, sizeof(int),len,wfile);
    }

    //关闭文件
    fclose(file);
    fclose(wfile);

    return 0;
}

