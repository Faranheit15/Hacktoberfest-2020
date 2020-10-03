#include<stdio.h>
char ifix[200],pfix[200],stack[100];
int p=0,s=0,i=0;
void fun()
{
    if(ifix[i]==')')
    {
        s--;
        while(stack[s]!='(')
            pfix[p++]=stack[s--];
    }
    if(ifix[i]=='+' || ifix[i]=='-')
    {
        if(!s)
            stack[s++]=ifix[i];
        else if(stack[s-1]=='(')
            stack[s++]=ifix[i];
        else
        {
            s--;
            while(s!=-1 && stack[s]!='(')
            {
                pfix[p++]=stack[s--];
            }
            stack[++s]=ifix[i];
            s++;
        }
    }
}
int main()
{
    printf("Enter your infix expression(using operators +, -, %%, /, *) : ");
    scanf("%s",ifix);
    for(i;ifix[i]!='\0';i++)
    {
        if(ifix[i]!='*' && ifix[i]!='/' && ifix[i]!='-' && ifix[i]!='+' && ifix[i]!='(' && ifix[i]!=')' && ifix[i]!='%')
            pfix[p++]=ifix[i];
        else if(ifix[i]=='(' || ifix[i]=='*' || ifix[i]=='/' || ifix[i]=='%')
            stack[s++]=ifix[i];
        else
            fun();
    }
    if(ifix[i]=='\0')
    {
        if(s)
        {
            s--;
            while(s!=-1)
            {
                if(stack[s]==')' || stack[s]=='(')
                    s--;
                pfix[p++]=stack[s--];
            }
        }
        pfix[p]='\0';
    }
    printf("The postfix expression is : %s",pfix);
    return 0;
}
