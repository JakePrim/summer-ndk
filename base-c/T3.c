#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

//
struct Study{
    char *studyContent;//ѧϰ����
};
//�ṹ��Ƕ��
struct Student{
    char name[10];
    int age;
    char sex;
    struct Study study;//Clion���ߵ�д��
//    Study st;vs��д��
    struct Wan{
        char * wanContent;
    } wan;//����ṹ�����
};

int mainT3(){
    //ʹ�ýṹ��
    struct Student student = {"����",18,'N',
            {"ѧϰC����"},
            {"��Ϸ"}
    };
    //��ȡǶ�׵Ľṹ��
    student.study.studyContent;
    student.wan.wanContent;
    printf("������%s",student.name);
    return 0;
}