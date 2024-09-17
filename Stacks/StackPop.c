#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data)
{
  if(top == MAX - 1)
  {
    printf( "Stack Overflow\n");
    return;
  }
  top = top + 1;
  stack_arr[top] = data;
}

int pop(){
    int value;
    if(top == -1)
    {
        printf("stack underflow");
        exit(1);
    }
    value = stack_arr[top];
    top = top -1;
    return value;
}
void printStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int main()
{
  int data;
  push(1);
  push(2);
  push(3);
  push(4);

  data = pop();
  data = pop();

  printStack();
  return 0;
}