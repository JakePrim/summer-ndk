#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//解密文件
int main(){
    char * fileNameStrEncode= "D:\\1encode.png";//加密的文件
    char * fileNameStrDecode= "D:\\1decode.png";//解密后文件

    FILE * encodeFile = fopen(fileNameStrEncode,"rb");
    FILE * decodeFile = fopen(fileNameStrDecode,"wb");

    if(!encodeFile || !decodeFile){
        printf("文件打开失败");
        exit(0);
    }
    //加密文件：把每一个字节拿出来，对每一个字节进行处理(全部加密)。把某一部分内容拿出来处理(部分加密)
    //异或处理 10 ^ 5 = 11111
    //解密：还原 1111 ^ 5 = 10
    //密钥
    char * password = "123456";
    int c;//接受读取的值
    int index = 0;
    int pass_len = strlen(password);
    //fgetc 返回值EOF=-1 就会没有了false
    while ((c= fgetc(encodeFile)) != EOF){
        char item = password[index%pass_len];
        printf("item=%c\n",item);
        //加密操作 对c进行异或操作
        fputc(c^item,decodeFile);
        index++;
    }
    //关闭文件
    fclose(encodeFile);
    fclose(decodeFile);
    return 0;
}

