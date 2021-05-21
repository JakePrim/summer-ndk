#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * C/C++ ������ �����������Ϊ�������ݣ���������Ż���ָ��-Ϊ�˸�Ч��
 * @param string
 * @return
 */
int getLen(char * string){
    printf("�ֽ���:%d",sizeof (string));//4
    int count = 0;
    while (*string){//*string != '\0' �ͻ�һֱѭ������
        string++;//�ƶ�ָ��
        count++;
    }
    return count;
}

/**
 * C�����д��
 * @param resultLen ʹ��ָ����Ϊ���� ע�⴫�ݵ��ǵ�ַ
 * @param arr ���� ������Ż���ָ��
 */
void getLen2(int *resultLen,int arr[]){
    int count = 0;
    while (*arr != '\0'){
        arr++;
        count++;
    }
    //��ָ�븳ֵ
    *resultLen = count;
}

/**
 * ���ַ���ȫ��ת��ΪСд
 * @param dest
 * @param name
 */
void lower(char *dest,char *name){
    //��Ҫ�ƻ�nameָ��ĵ�ַ�������ⲿ��Ҳ��ı�
    char *temp = name;
    while (*temp){
        //һ�����ַ���ת��
        *dest = tolower(*temp);
        //Ų��ָ��
        temp++;
        dest++;
    }
    //destָ��ĵ�ַָ�������
    *dest = '\0';//�����ӡϵͳֵ
}

/**
 * ��ȡ�ַ���
 * @param result ��ȡ�Ľ��
 * @param dest Ŀ���ַ���
 * @param start ��ʼ��λ��
 * @param end ������λ��
 */
void cutout(char *result,char *dest,int start,int end){
    if (start > end){
        *result = '\0';
    }
    //��Ҫ�ƻ�dest
    char * temp = dest;
    temp+=start;//ֱ�ӽ���ַ�ƶ�����ʼ��λ��
    for (int i = start; i < end; ++i) {
        *result = *temp;
        result++;
        temp++;
    }
    *result = '\0';
}

/**
 * ��ȡ�ַ�����д��
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
//    //��һ�ּ򻯷�ʽ������ָ���һ��ָ����и�ֵ
//    strcpy(*result,resultArr);
//
//    printf("%s\n",resultArr);
}

/**
 * �����ַ�ʽ
 * @param result
 * @param dest
 * @param start
 * @param end
 */
void cutout3(char *result,char *dest,int start,int end){
    //��д��
    for (int i = start; i < end; ++i) {
        *(result++) = *(dest+i);
    }
}

/**
 * �����ַ�ʽ
 */
void cutout4(char *result,char *dest,int start,int end){
    //����1 ��ֵ��������
    //����2 ֱ�Ӵ�start��λ�ÿ�ʼ
    //����3 copy�ĸ���
    strncpy(result,dest+start,(end-start));
}

/**
 * �ַ��������ִ�����ʽ
 * @return
 */
int main(){
    printf("123");
    //ͨ�����鴴���ַ���
    char str[] = {'H','e','l','l','o','\0'};
    str[2] = 'r';
    //ע��printf ��������\0�Ż������������������⣬�������ĩβ����\0
    printf("��һ�ַ�ʽ:%s\n",str);//��һ�ַ�ʽ:Hello����������L?�Xs?

    //ͨ��ָ�봴���ַ���
    char * str2 = "Hello";// Ĭ�ϻ���ĩβ����\0��������
    str2[2] = 'r';//��������?? ��������� ����IDEû�������أ� ��Ϊstr2ָ�����һ����ַ �����޸�ȫ�������ַ���
    printf("�ڶ��ַ�ʽ:%s\n",str2);

    //ָ��Ų����ȡ�ַ�����Ϣ
    char string[] = {'a','b','c','d','0','\0'};
    int len = getLen(string);
    printf("����Ϊ:%d\n",len);//5

    int intarr[] = {1,2,3,4,5,6,0,7,'\0'};//��β��Ҫ�н������� �� '\0'
    int len2 = sizeof(intarr)/sizeof (int);
    printf("����:%d\n",len2);//����:8

    int count;
    //���ݵ�ַ
    getLen2(&count,intarr);
    printf("���Գ���:%d\n",count);//���Գ���:7

    //�ַ�����ת��
    char *num = "1";
    num = "123.xxx";//ת��Ϊ123
    num = "0";
    int result = atoi(num);//atoi ת��Ϊint����
    if (result){
        printf("ת�����:%d\n",result);
    }
    //atof(); ת��double����

    //�ַ����ıȽ�
    char * strr1 = "jake";
    char * strr2 = "jake";
    //strcmp ���ִ�Сд
    //strcmpi() �����ִ�Сд
    int res = strcmp(strr1,strr2);//-1 ��ʾ����� 0 ��ʾ��ȵ�
    printf("�ַ����ȽϽ��:%d\n",res);

    //�ַ����Ĳ��ҡ�������ƴ��
    char * text = "name is Derry";
    char * subtext = "D";

    //strstr �ַ������������
    char *pop = strstr(text,subtext);

    printf("���ҵĽ��:%c\n",*pop);//���ҵĽ��:D

    //������ֵ�λ��
    int index = pop - text;//ʹ��pop��ָ���ַ - text��ָ���ַ�ͻ�õ�λ��
    printf("���ֵ�λ��:%d\n",index);//���ֵ�λ��:8

    //ƴ���ַ���
    char destination[25];// ���ȶ�������
    char *black = "--��--",*CPP="cpp",*Java="Java";
    strcpy(destination,CPP);//��copy��������ȥ
    strcat(destination,black);//�ڽ���ƴ��
    strcat(destination,Java);//Ȼ����ƴ��Java
    printf("ƴ�Ӻ�Ľ��:%s\n",destination);//ƴ�Ӻ�Ľ��:cpp--��--Java

    //��Сдת��
    char * name = "JakePrim";
    //ȫ�����Сд
    char dist[20];
    lower(dist,name);
    printf("ת����Ľ��:%s\n",dist);//ת����Ľ��:jakeprim

    //��ȡ�ַ���
    char result2[1000]="ABC";
    cutout4(result2,name,2,6);
    printf("��ȡ���ַ���:%s\n",result2);//��ȡ���ַ���:kePr


    return 0;
}