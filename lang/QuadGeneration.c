#include <stdio.h>
#include "header.h"
#include "y.tab.h"
#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

// check
// int y=0;
//     bool x = y>=0 & (y==0 | y!=0);
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************Variables***************************************************
static int lbl = 0;
char arr[10] = "";
int st[100][10];
int topif1 = 0;
int topif2 = 0;
char *new;
int stackif1[100];
int stackif2[100];
int tempvar = 0;
int stacktempvar[100];
int toptempvar = 0;
int tempval = 0;
bool tempexist = false;
int tempexp = 0;
bool switchexp=false;
int switchval=0;
nodeType *newp=NULL;

//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//***********************************************Prototypes************************************************

void push(int x, int stack);

int pop(int stack);

void expresion(nodeType *p, char *string, int lbl1, int lbl2, int oper);

//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************

int ex(nodeType *p, int lbl1, int lbl2)
{
    //printf("/nhi/n");

    if (!p)
        return 0;
    switch (p->type)
    {

        //*********************************************************************************************************
    case typeCon:
        if (p->con.type == typeint)
            printf(" %d", p->con.intVal);
        else if (p->con.type == typebool)
            printf(p->con.boolVal ? "true" : "false");
        else if (p->con.type == typefloat)
            printf(" %.4f", p->con.floatVal);
        else if (p->con.type == typestring)
            printf(" %s", p->con.strVal);
        break;

        //*********************************************************************************************************
    case typeId:
        printf(" %s", (p->id.label));
        break;
        //*********************************************************************************************************

    case typeOpr:
        switch (p->opr.oper)
        {

            //*********************************************************************************************************
        case WHILE:
            lbl1 = lbl++;
            push(lbl1, 0);
            printf("L%03d:\n", lbl1);
            ex(p->opr.op[0], lbl1, lbl2);
            printf("\n\tJNEQ");
            int tempwhile = pop(2);
            printf(" Temp%d", tempwhile);
            lbl2 = lbl++;
            push(lbl2, 1);
            printf(" L%03d\n", lbl2);
            ex(p->opr.op[1], lbl1, lbl2);
            int popjmp = pop(0);
            printf("\tjmp\tL%03d\n", popjmp);
            int popcon = pop(1);
            printf("L%03d:\n", popcon);
            break;

            //*********************************************************************************************************

        case FOR:
            ex(p->opr.op[0], lbl1, lbl2);
            lbl1 = lbl++;
            push(lbl1, 0);
            printf("L%03d:\n", lbl1);
            ex(p->opr.op[1], lbl1, lbl2);
            printf("\n\tJNEQ");
            int tempfor = pop(2);
            printf(" Temp%d", tempfor);
            lbl2 = lbl++;
            push(lbl2, 1);
            printf(" L%03d\n", lbl2);
            ex(p->opr.op[2], lbl1, lbl2);
            int popjmpfor = pop(0);
            printf("\tjmp\tL%03d\n", popjmpfor);
            int popconfor = pop(1);
            printf("L%03d:\n", popconfor);
            break;

            //*********************************************************************************************************
        case DO:
            lbl1 = lbl++;
            push(lbl1, 0);
            printf("L%03d:\n", lbl1);
            ex(p->opr.op[0], lbl1, lbl2);
            ex(p->opr.op[1], lbl1, lbl2);
            printf("\n\tJNEQ");
            int tempdo = pop(2);
            printf(" Temp%d", tempdo);
            lbl2 = lbl++;
            push(lbl2, 1);
            printf(" L%03d\n", lbl2);
            int popjmpdo = pop(0);
            printf("\tjmp\tL%03d\n", popjmpdo);
            int popdo = pop(1);
            printf("L%03d:\n", popdo);
            break;

            //*********************************************************************************************************
        case IF:
            ex(p->opr.op[0], lbl1, lbl2);
            /* if else */
            lbl1 = lbl++;
            printf("\n\tJNEQ");
            int temp = pop(2);
            printf(" Temp%d", temp);
            push(lbl1, 0);
            printf("  L%03d\n", lbl1);

            ex(p->opr.op[1], lbl1, lbl2);
            if (p->opr.op[1]->type != typeOpr || p->opr.op[1]->opr.oper != ELSE)
            {
                int lbl3 = pop(0);
                printf("L%03d:\n", lbl3);
            }
            break;
            //*********************************************************************************************************

        case SWITCH:
            lbl2 = lbl++;
            push(lbl2, 0);
            if(p->opr.op[0]->type==typeOpr)
            {
            ex(p->opr.op[0], lbl1, lbl2);
            tempexp = pop(2);
            switchexp=true;

            }
            else
                newp=p->opr.op[0];
            
            
            ex(p->opr.op[1], lbl1, lbl2);
            int last = pop(0);
            printf("L%03d:\n", last);

            break;

            //*********************************************************************************************************
        case '=':

            if (p->opr.op[1]->type == typeOpr)
            {
                ex(p->opr.op[1], lbl1, lbl2);
                printf("\n");
                printf("\tASSIGN %c ", p->opr.op[0]->id.label);
                int temp = pop(2);
                printf(" Temp%d", temp);
                tempexist = false;
            }
            else
            {
                printf("\tASSIGN %s ", p->opr.op[0]->id.label);
                ex(p->opr.op[1], lbl1, lbl2);
            }
            printf("\n");
            break;

            //*********************************************************************************************************

        default:
            if (p->opr.oper == ELSE)
            {
                ex(p->opr.op[0], lbl1, lbl2);
                lbl2 = lbl++;
                push(lbl2, 1);
                printf("\tjmp\tL%03d\n", lbl2);
                int lbl3 = pop(0);
                printf("L%03d:\n", lbl3);
                ex(p->opr.op[1], lbl1, lbl2);
                int lbl4 = pop(1);
                printf("L%03d:\n", lbl4);
                break;
            }
            switch (p->opr.oper)
            {
                //*********************************************************************************************************
            case '+':
                expresion(p, "add", lbl1, lbl2, 2);
                break;

                //*********************************************************************************************************
            case '-':
                expresion(p, "sub", lbl1, lbl2, 2);
                break;

                //*********************************************************************************************************
            case '*':
                expresion(p, "mult", lbl1, lbl2, 2);
                break;

                //*********************************************************************************************************
            case '/':
                expresion(p, "div", lbl1, lbl2, 2);
                break;

                //*********************************************************************************************************
            case '~':
                expresion(p, "NEG", lbl1, lbl2, 1);
                break;

                //*********************************************************************************************************
                //AND w OR fehom moshkela
            case '&':
                expresion(p, "And", lbl1, lbl2, 2);
                break;
                //*********************************************************************************************************
            case '|':
                expresion(p, "OR", lbl1, lbl2, 2);
                break;

                //*********************************************************************************************************
            case '<':
                expresion(p, "CompLT", lbl1, lbl2, 2);
                break;

                //*********************************************************************************************************
            case '>':
                expresion(p, "compGT", lbl1, lbl2, 2);
                break;

                //*********************************************************************************************************
            case COND_GREQ:
                expresion(p, "compGTEQ", lbl1, lbl2, 2);
                break;

                //*********************************************************************************************************
            case COND_LSEQ:
                expresion(p, "compLTEQ", lbl1, lbl2, 2);
                break;
                //*********************************************************************************************************

            case COND_NEQ:
                expresion(p, "compNEQ", lbl1, lbl2, 2);
                break;
                //*********************************************************************************************************

            case COND_EQ:
                expresion(p, "compEQ", lbl1, lbl2, 2);
                break;

                //*********************************************************************************************************

            case ';':
                ex(p->opr.op[0], lbl1, lbl2);
                ex(p->opr.op[1], lbl1, lbl2);
                break;

            //*********************************************************************************************************
            case CASE:;

                int first = pop(0);
                printf("L%03d:\n", first);
                bool exp0 = false;
                if (p->opr.op[0]->type == typeOpr)
                {
                    ex(p->opr.op[0], lbl1, lbl2);
                    exp0 = true;
                }

                int tempexp2;
                printf("\n");
                printf("\t%s", "compEQ");
                if(switchexp)
                printf(" Temp%d", tempexp);
                else
                {
                    ex(newp, lbl1, lbl2);
                }
                if (exp0)
                {
                    tempexp2 = pop(2);
                    printf(" Temp%d", tempexp2);
                }
                else
                    ex(p->opr.op[0], lbl1, lbl2);

                printf(" Temp%d ", tempval);
                push(tempval, 2);
                tempval++;
                printf("\n");
                printf("\n\tJNEQ");
                int tempswitch = pop(2);
                printf(" Temp%d", tempswitch);
                lbl2 = lbl++;
                push(lbl2, 0);
                printf(" L%03d\n", lbl2);
                ex(p->opr.op[1], lbl1, lbl2);
                break;

            //*********************************************************************************************************
            case CASE_JOIN:
                ex(p->opr.op[0], lbl1, lbl2);
                ex(p->opr.op[1], lbl1, lbl2);
                break;

            //*********************************************************************************************************
            case CONST:
                printf("DECCONST");
                ex(p->opr.op[0], lbl1, lbl2);
                ex(p->opr.op[1], lbl1, lbl2);
                printf("\n");
                break;

            //*********************************************************************************************************
            case DEC:

                if (p->opr.nops == 1)
                {
                    
                    ex(p->opr.op[0], lbl1, lbl2);
                }
                else
                {
                    bool declared=false;
                    if (p->opr.op[1]->type == typeOpr)
                    {
                        ex(p->opr.op[1], lbl1, lbl2);
                        declared=true;
                    }
                    printf("DECVAR");
                    ex(p->opr.op[0], lbl1, lbl2);
                    if(declared)
                    {
                        int tempdec=pop(2);
                        printf(" Temp%d", tempdec);
                    }
                    else
                    {
                        ex(p->opr.op[1], lbl1, lbl2);
                    }
                    
                    
                }

                printf("\n");
                break;

            default:
                break;
            }
        }
    }
    return 0;
}

//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************

void push(int x, int stack)
{
    if (topif1 >= 99 || topif2 >= 99)
    {
        printf("\n\tSTACK is over flow");
    }
    else
    {
        // printf("\n /n %d /n \n",x);
        if (stack == 0)
        {
            stackif1[topif1] = x;
            topif1++;
        }
        else if (stack == 1)
        {
            stackif2[topif2] = x;
            topif2++;
        }
        else if (stack == 2)
        {
            stacktempvar[toptempvar] = x;
            toptempvar++;
        }
    }
}

//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************

int pop(int stack)
{
    if (topif1 <= -1 || topif2 <= -1)
    {
        printf("\n\t Stack is under flow\n");
        return 0;
    }
    else
    {

        int x;
        if (stack == 0)
        {
            topif1--;
            x = stackif1[topif1];
        }
        else if (stack == 1)
        {
            topif2--;
            x = stackif2[topif2];
        }
        else if (stack == 2)
        {
            toptempvar--;
            x = stacktempvar[toptempvar];
        }

        return x;
    }
}

//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
void expresion(nodeType *p, char *string, int lbl1, int lbl2, int oper)
{
    bool doneop0 = false;
    bool doneop1 = false;
    int valuepop0 = 0;
    int valuepop1 = 0;

    if (p->opr.op[0]->type == typeOpr)
    {

        ex(p->opr.op[0], lbl1, lbl2);
        valuepop0 = pop(2);
        doneop0 = true;
    }
    if (p->opr.op[1]->type == typeOpr)
    {
        ex(p->opr.op[1], lbl1, lbl2);
        valuepop1 = pop(2);
        doneop1 = true;
    }
    printf("\n");
    printf("\t%s", string);
    if (!doneop0)
    {
        ex(p->opr.op[0], lbl1, lbl2);
    }
    else
    {
        printf(" Temp%d", valuepop0);
    }
    if (oper == 2 && !doneop1)
        ex(p->opr.op[1], lbl1, lbl2);
    else
    {
        printf(" Temp%d", valuepop1);
    }

    printf(" Temp%d ", tempval);
    tempexist = true;
    push(tempval, 2);
    tempval++;
    printf("\n");
}
