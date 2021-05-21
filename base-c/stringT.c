#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * C/C++ 编译器 如果把数组作为参数传递，会把数据优化成指针-为了高效率
 * @param string
 * @return
 */
int getLen(char * string){
    printf("字节数:%d",sizeof (string));//4
    int count = 0;
    while (*string){//*string != '\0' 就会一直循环遍历
        string++;//移动指针
        count++;
    }
    return count;
}

/**
 * C正规的写法
 * @param resultLen 使用指针作为返回 注意传递的是地址
 * @param arr 参数 数组会优化成指针
 */
void getLen2(int *resultLen,int arr[]){
    int count = 0;
    while (*arr != '\0'){
        arr++;
        count++;
    }
    //给指针赋值
    *resultLen = count;
}

/**
 * 把字符串全部转换为小写
 * @param dest
 * @param name
 */
void lower(char *dest,char *name){
    //不要破坏name指针的地址，否则外部的也会改变
    char *temp = name;
    while (*temp){
        //一个个字符的转换
        *dest = tolower(*temp);
        //挪动指针
        temp++;
        dest++;
    }
    //dest指针的地址指向了最后
    *dest = '\0';//避免打印系统值
}

/**
 * 截取字符串
 * @param result 截取的结果
 * @param dest 目标字符串
 * @param start 开始的位置
 * @param end 结束的位置
 */
void cutout(char *result,char *dest,int start,int end){
    if (start > end){
        *result = '\0';
    }
    //不要破坏dest
    char * temp = dest;
    temp+=start;//直接讲地址移动到开始的位置
    for (int i = start; i < end; ++i) {
        *result = *temp;
        result++;
        temp++;
    }
    *result = '\0';
}

/**
 * 截取字符串简化写法
 * @param result
 * @param dest
 * @param start
 * @param end
 */
void cutout2(char **result,char *dest,int start,int end){
//    int *temp = dest;
//    int count=0;
//    char resultArr[end - start];
//    for (int i = 0; i < start; ++i) {
//        resultArr[count] = *temp;
//        temp++;
//    }
//    //第一种简化方式：二级指针的一级指针进行赋值
//    strcpy(*result,resultArr);
//
//    printf("%s\n",resultArr);
}

/**
 * 第三种方式
 * @param result
 * @param dest
 * @param start
 * @param end
 */
void cutout3(char *result,char *dest,int start,int end){
    //简化写法
    for (int i = start; i < end; ++i) {
        *(result++) = *(dest+i);
    }
}

/**
 * 第四种方式
 */
void cutout4(char *result,char *dest,int start,int end){
    //参数1 赋值到容器中
    //参数2 直接从start的位置开始
    //参数3 copy的个数
    strncpy(result,dest+start,(end-start));
}

/**
 * 字符串的两种创建方式
 * @return
 */
int main(){
    printf("123");
    //通过数组创建字符串
    char str[] = {'H','e','l','l','o','\0'};
    str[2] = 'r';
    //注意printf 必须遇到\0才会结束否则会有乱码问题，在数组的末尾加上\0
    printf("第一种方式:%s\n",str);//第一种方式:Hello烫烫烫蹄鼭L?╔s?

    //通过指针创建字符串
    char * str2 = "Hello";// 默认会在末尾加上\0结束符号
    str2[2] = 'r';//这里会崩溃?? 不允许访问 但是IDE没有问题呢？ 因为str2指向的是一个地址 不能修改全局区的字符串
    printf("第二种方式:%s\n",str2);

    //指针挪动获取字符串信息
    char string[] = {'a','b','c','d','0','\0'};
    int len = getLen(string);
    printf("长度为:%d\n",len);//5

    int intarr[] = {1,2,3,4,5,6,0,7,'\0'};//结尾需要有结束符号 ： '\0'
    int len2 = sizeof(intarr)/sizeof (int);
    printf("长度:%d\n",len2);//长度:8

    int count;
    //传递地址
    getLen2(&count,intarr);
    printf("测试长度:%d\n",count);//测试长度:7

    //字符串的转换
    char *num = "1";
    num = "123.xxx";//转换为123
    num = "0";
    int result = atoi(num);//atoi 转换为int类型
    if (result){
        printf("转换结果:%d\n",result);
    }
    //atof(); 转化double类型

    //字符串的比较
    char * strr1 = "jake";
    char * strr2 = "jake";
    //strcmp 区分大小写
    //strcmpi() 不区分大小写
    int res = strcmp(strr1,strr2);//-1 表示不相等 0 表示相等的
    printf("字符串比较结果:%d\n",res);

    //字符串的查找、包含、拼接
    char * text = "name is Derry";
    char * subtext = "D";

    //strstr 字符串查找与包含
    char *pop = strstr(text,subtext);

    printf("查找的结果:%c\n",*pop);//查找的结果:D

    //计算出现的位置
    int index = pop - text;//使用pop的指针地址 - text的指针地址就会得到位置
    printf("出现的位置:%d\n",index);//出现的位置:8

    //拼接字符串
    char destination[25];// 首先定义容器
    char *black = "--到--",*CPP="cpp",*Java="Java";
    strcpy(destination,CPP);//先copy到数组中去
    strcat(destination,black);//在进行拼接
    strcat(destination,Java);//然后在拼接Java
    printf("拼接后的结果:%s\n",destination);//拼接后的结果:cpp--到--Java

    //大小写转换
    char * name = "JakePrim";
    //全部变成小写
    char dist[20];
    lower(dist,name);
    printf("转换后的结果:%s\n",dist);//转换后的结果:jakeprim

    //截取字符串
    char result2[1000]="ABC";
    cutout4(result2,name,2,6);
    printf("截取的字符串:%s\n",result2);//截取的字符串:kePr


    return 0;
}