//
// Created by DaisyN on 2021-07-12.
// 线性表的顺序存储：利用数组的连续存储空间顺序存放线性表的各个元素

#include "stdio.h"
#define MAXSIZE 20    /*定义存储空间初始分配量*/
#define true 1
#define false 0
typedef int ElementType; /*定义存储数据的类型*/

typedef struct {
    ElementType data[MAXSIZE];
    int length;
}List;

/* 初始化(建立空的顺序表)*/
int InitList(List *L){
    L -> length = 0; // 访问List中的length将其设置为0
    return true;
}
/* 判断线性表是否为空，为空返回true，不为空返回false */
int ListEmpty(List L){
    if(L.length==0) return true;
    else return false;
}
/* 返回线性表L的元素个数*/
int ListLength(List *L){
    return L->length;
}

/* 线性表存在，将其清空*/
int ClearList(List *L){
    L->length = 0;
    return true;
}
/*将线性表L中的第i个位置元素返回给e*/
int GetElem(List L,int i,ElementType *e){
    //需要判断i的位置
    if(L.length==0||i<1||i>L.length) return false;
    //注意顺序存储是从0开始的
    *e = L.data[i-1];
    return true;
}
/* 在线性表L中查照与给定值e相等的元素，如果查找失败，返回0，如果成功，返回元素位置*/
int LocateElem(List L,ElementType e){
    int i;
    // 一定不要忘记空列表的判断
    if (L.length==0) return false;
    for(i=0;i<L.length;i++){
        if (L.data[i]==e) break;
    }
    return i+1;
}
int ListInsert(List *L,int i,ElementType e){
    int j;
    //需要先判断线性表是否已经满了
    if(L->length>=MAXSIZE) return false;
    //判断插入位置是否小于0或者大于最后一位的后面一位
    if(i<0||i>L->length+1) return false;
    //插入元素不在末尾时,所有元素向后移动一位
    if(i<=L->length){
        for (j = L->length-1; j>=i-1 ; j--) {
            L->data[j+1] = L->data[j];
        }
    }
    //插入元素在末尾时
        L->data[i-1]=e; //第i位为插入元素
        L->length++; //长度加1
    return true;
}
/*删除L的第i个数据元素，并用e返回其值，L的长度减1 */
int ListDelete(List *L,int i,ElementType *e){
    int k;
    if(i>L->length||i<1) return false;
    if(L->length==0) return false;
    *e = L->data[i-1];
    /* 如果删除的位置不是最后位置 */
    if (i<L->length){
        for(k=i;k<L->length;k++)  // 将删除位置后继元素前移
            L->data[k-1]=L->data[k];
    } else L->data[L->length-1] =0;
    L->length--;
    return true;
}

int main(){
    List l;
    ElementType e;
    int i,j,k,n;
    // 初始化列表
    InitList(&l);
    printf("The list length is %d\n",l.length);
    for ( j = 1; j < 10; j++) {
        //插入元素
        ListInsert(&l,1,j);
    }
    printf("The list length is %d\n", ListLength(&l));
    // 访问每个元素
    for (int k = 0; k < l.length; k++) {
        printf("The %d item is %d\n",k,l.data[k]);
    }
    i=ListEmpty(l);
    printf("l is empty? i=%d(1:Y 0:N)\n",i);
    ListDelete(&l,8,&k);
    // 第8位对应的是2，从0开始的
    printf("the number is %d\n",k);
    k =5;
    GetElem(l,k,&e);
    printf("the number is %d\n",e);
    // 清空列表
    ClearList(&l);
    // 判断列表是否为空
    i=ListEmpty(l);
    printf("l is empty? i=%d(1:Y 0:N)\n",i);
}