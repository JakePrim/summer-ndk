#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//文件加密与文件解密
int main(){
    char * fileNameStr = "D:\\1.png";//要加密的文件
    char * fileNameStrEncode= "D:\\1encode.png";//加密后的文件

    //读取要加密的文件
    FILE * file = fopen(fileNameStr,"rb");
    //写入加密后的文件
    FILE * fileEncode = fopen(fileNameStrEncode,"wb");//wb 会自动厂家按文件

    if(!file || !fileEncode){
        printf("文件打开失败");
        exit(0);
    }
    //加密文件：把每一个字节拿出来，对每一个字节进行处理(全部加密)。把某一部分内容拿出来处理(部分加密)
    //异或处理 10 ^ 5 = 11111
    //解密：还原 1111 ^ 5 = 10
    int c;//接受读取的值
    //fgetc 返回值EOF=-1 就会没有了false
    while ((c= fgetc(file)) != EOF){
        //加密操作 对c进行异或操作
        fputc(c^5,fileEncode);
    }
    //关闭文件
    fclose(file);
    fclose(fileEncode);

    //解密文件==还原之前的样子

    return  0;
}

