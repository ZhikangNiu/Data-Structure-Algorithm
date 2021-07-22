//
// Created by DaisyN on 2021-07-18.
//

#include "stdio.h"

#define MAXSIZE 20
#define true 1
#define false 0

typedef int Status;
typedef int ElemType;
/*栈的结构*/
typedef struct {
    ElemType data[MAXSIZE];
    int top; //用于栈顶指针,当前元素的栈顶序号
}Stack;
/*初始化栈*/
Status InitStack(Stack *s){
    s->top = -1;
    return true;
}
/*将栈设置为空*/
Status ClearStack(Stack *s){
    s->top = -1;
    return true;
}
/*求栈的长度*/
Status StackLength(Stack *s){
    return s->top+1;
}
/* 插入元素e为新的栈顶元素 */
Status push(Stack *s,ElemType e){
    if(s->top>=MAXSIZE-1){
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}
/* 若栈S为空栈，则返回true，否则返回false */
Status StackEmpty(Stack S)
{
    return S.top == -1? true:false;
    /*
    if (S.top==-1)
        return true;
    else
        return false;
    */
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回true；否则返回false */
Status pop(Stack *s,ElemType *e){
    if(s->top < 0) return false;
    *e = s->data[s->top];//返回栈顶元素
    s->top--;
    return true;
}
/* 从栈底到栈顶依次对栈中每个元素显示 */
Status StackTraverse(Stack *s)
{
    int i;
    i=0;
    while(i<=s->top)
    {
        printf("%d ",s->data[i++]);
    }
    printf("\n");
    return true;
}
/*获得栈顶元素*/
Status GetTop(Stack S,ElemType *e)
{
    if (S.top==-1) return false;
    else
        *e=S.data[S.top];
    return true;
}
int main()
{
    int j;
    Stack s;
    int e;
    if(InitStack(&s)==true)
        for(j=1;j<=10;j++)
            push(&s,j);
    printf("The stack items are listed as follows:");
    StackTraverse(&s);
    pop(&s,&e);
    printf("The top item is e=%d\n",e);
    printf("Is the Stack empty?:%d(1:Yes 0:No)\n",StackEmpty(s));
    GetTop(s,&e);
    printf("The top item is e=%d and the length is %d\n",e,StackLength(&s));
    ClearStack(&s);
    printf("After cleaning the stack .Is it empty? :%d(1:Yes 0:No)\n",StackEmpty(s));

    return 0;
}

