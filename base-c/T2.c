#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/**
 * �ṹ����൱��Java�е���ĸ���
 * @return
 */
struct Dog{
    //�����Ա
    char name[10];
    char *n;//����ֱ�Ӹ�ֵ
    int age;
    char sex;
} g1 = {"gs","g",2,'M'},g2={"g3","g",4,'G'},g3;//��β������;��������


int mainT2(){
    //ʹ�ýṹ��
    struct Dog dog;//����д����û�������ʼ���� ��ԱĬ��ֵ��ϵͳֵ(����)
    //��ֵ����
    //ע�����鸳ֵ ��Ҫʹ��strcpy api����
    strcpy(dog.name,"����");
    dog.age = 3;
    dog.sex = 'G';

    printf("name:%s,age:%d,sex:%c\n",dog.name,dog.age,dog.sex);//name:����,age:3,sex:G

    //ֱ��ʹ��
    g3.n = "123";//ָ�벻��ʹ��strcpy ���и�ֵ
    printf("name:%s,age:%d,sex:%c\n",g1.name,g1.age,g1.sex);//name:gs,age:2,sex:M

    return 0;
}
