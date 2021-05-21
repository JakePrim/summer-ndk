#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//使用密钥加密
int main(){
    char * fileNameStr = "D:\\1.png";//要加密的文件
    char * fileNameStrEncode= "D:\\1encode.png";//加密后的文件

    //读取要加密的文件
    FILE * file = fopen(fileNameStr,"rb");
    //写入加密后的文件
    FILE * fileEncode = fopen(fileNameStrEncode,"wb");//wb 会自动厂家按文件

    //密钥
    char * password = "123456";

    if(!file || !fileEncode){
        printf("文件打开失败");
        exit(0);
    }
    int c;
    int index = 0;
    int pass_len = strlen(password);
    while ((c= fgetc(file))!=EOF){
        char item = password[index%pass_len];
        printf("item=%c\n",item);
        fputc(c ^ item,fileEncode);
        index++;
    }
    fclose(file);
    fclose(fileEncode);
    return 0;
}
