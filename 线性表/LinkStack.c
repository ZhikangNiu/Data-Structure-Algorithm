//
// Created by DaisyN on 2021-07-20.
//
#include "stdio.h"
#include "stdlib.h"
#define true 1
#define false 0
typedef int Status;
typedef int ElemType;
typedef struct StackNode{
    ElemType data;
    struct StackNode *next;//指向下一个的指针
}StackNode,*LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;// LinkStackPtr是指向StackNode的一个指针
    int count;
}LinkStack;
// 相当于LinkStack由许多LinkStackNode组成

Status InitStack(LinkStack *S){\
    //相当于是初始化头结点
    LinkStackPtr s = S->top;
    s = (LinkStackPtr) malloc(sizeof (StackNode));
    if(!s) return false;//开辟内存失败
    S->top =NULL;
    S->count = 0;
    return true;
}
//清空链栈
Status ClearStack(LinkStack *S){
    /*
    S->top = NULL;
    S->count = 0;
     不能这么写
     */
    LinkStackPtr p,q;
    p = S->top;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    S->count = 0;
    return true;
}
//插入新的元素
Status Push(LinkStack *S,ElemType e){
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));//分配空间
    s->data = e;
    s->next = S->top;
    S->top++;  //栈顶元素增加
    S->count++; //栈中数量增加
    return true;
}
// 判断链栈是否为空
Status StackEmpty(LinkStack S) {
    return S.count == 0?true:false;
}
// 求链栈的长度
int Length(LinkStack *S){
    return S->count;
}
// 弹出元素，并用元素e返回
Status Pop(LinkStack *S,ElemType *e){
    LinkStackPtr s;
    if(StackEmpty(*S)) return false;
    *e = S->top->data;//顶部元素由e返回
    s = S->top;
    S->top = S->top->next;
    free(s);//释放空间
    S->count--;
    return true;
}
Status GetTop(LinkStack *S,ElemType *e){
    if(S->count ==0||S->top==NULL) return false;
    *e = S->top->data;
    return true;
}
Status visit(ElemType c)
{
    printf("%d ",c);
    return true;
}
Status StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p=S.top;
    while(p){
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return true;
}

int main()
{
    int j;
    LinkStack s;
    int e;
    if(InitStack(&s)==true)
        for(j=1;j<=10;j++)
            Push(&s,j);
    printf("The items are listed as follows:");
    StackTraverse(s);
    Pop(&s,&e);
    printf("Pop item is e=%d\n",e);
    printf("Empty? %d(1:空 0:否)\n",StackEmpty(s));
    GetTop(&s,&e);
    printf("Top item is e=%d Length is %d\n",e,Length(&s));
    ClearStack(&s);
    printf("After cleaning, Empty? %d(1:空 0:否)\n",StackEmpty(s));
    return 0;
}