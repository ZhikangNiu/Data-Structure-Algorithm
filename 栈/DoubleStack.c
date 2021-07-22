//
// Created by DaisyN on 2021-07-19.
//
#include "stdio.h"
#define true 1
#define false 0
#define MAXSIZE 20
typedef int ElemType;
typedef int Status;
// 两栈共享的空间结构
typedef struct{
    ElemType data[MAXSIZE];
    int top1;//栈1顶
    int top2;//栈2顶
}DoubleStack;
Status InitStack(DoubleStack *D){
    D->top1 = -1;
    D->top2 = MAXSIZE;
    return true
    ;
}
Status ClearStack(DoubleStack *D){
    D->top1=-1;
    D->top2=MAXSIZE;
    return true;
}
Status StackEmpty(DoubleStack *D){
    if(D->top1 == -1 && D->top2 == MAXSIZE)
        return true;
    else
        return false;
}
int StackLength(DoubleStack D){
    return D.top1+1+MAXSIZE-D.top2;
}
Status Show(DoubleStack D){
    int i = 0;
    int j = MAXSIZE-1;
    for (i = 0; i < D.top1+1; i++) {
        printf("Stack1 %d ",D.data[i]);
    }
    printf("\n");
    for ( j; j > D.top2-1 ; j--) {
        printf("Stack2 %d ",D.data[j]);
    }
    printf("\n");
    return true;
}
/* 插入元素e为新的栈顶元素 */
Status Push(DoubleStack *S,ElemType e,int StackNumber)
{
    if (S->top1+1==S->top2)	/* 栈已满，不能再push新元素了 */
        return false;
    if (StackNumber==1)			/* 栈1有元素进栈 */
        S->data[++S->top1]=e; /* 若是栈1则先top1+1后给数组元素赋值。 */
    else if (StackNumber==2)	/* 栈2有元素进栈 */
        S->data[--S->top2]=e; /* 若是栈2则先top2-1后给数组元素赋值。 */
    return true;
}
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(DoubleStack *S,ElemType *e,int StackNumber){
    if (StackNumber==1){
        if (S->top1==-1) return false; /* 说明栈1已经是空栈，溢出 */
        *e=S->data[S->top1--]; /* 将栈1的栈顶元素出栈 */
    }
    else if (StackNumber==2){
        if (S->top2==MAXSIZE) return false; /* 说明栈2已经是空栈，溢出 */
        *e=S->data[S->top2++]; /* 将栈2的栈顶元素出栈 */
    }
    return true;
}
int main()
{
    int j;
    DoubleStack s;
    int e;
    if(InitStack(&s)==true){
        for(j=1;j<=5;j++)
            Push(&s,j,1);
        for(j=MAXSIZE;j>=MAXSIZE-2;j--)
            Push(&s,j,2);
    }

    printf("The DoubleStack has:\n");
    Show(s);

    printf("Length:%d \n",StackLength(s));

    Pop(&s,&e,2);
    printf("Stack2 pop item is e=%d\n",e);
    printf("Is Stack empty? %d(1:Y 0:N)\n",StackEmpty(&s));

    for(j=6;j<=MAXSIZE-2;j++)
        Push(&s,j,1);

    printf("The DoubleStack has following items now\n");
    Show(s);

    printf("Is the DoubleStack full ? %d(1:N 0:Y)\n",Push(&s,100,1));


    ClearStack(&s);
    printf("After cleaning the DoubleStack, empty? %d(1:y 0:n)\n",StackEmpty(&s));

    return 0;
}