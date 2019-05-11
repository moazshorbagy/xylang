#include <stdio.h>
#include "header.h"
#include "x.tab.h"
#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
//azwd if (y) w while (y) SCOPES

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
static int rownum=1;

//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//***********************************************Prototypes************************************************

void push(int x, int stack);

int pop(int stack);

void expresion(nodeType *p, char *string, int lbl1, int lbl2, int oper,FILE *fp);

//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************
//*********************************************************************************************************

int ex(nodeType *p, int lbl1, int lbl2,FILE *fp,int start)
{
    
 
   if(start==0)
   {
       fprintf(fp,"%d",rownum);
        rownum++;
        start++;
   }
  

    if (!p)
        return 0;
    switch (p->type)
    {
        

        //*********************************************************************************************************
    case typeCon:
        if (p->con.type == typeint)
            fprintf (fp," %d", p->con.intVal);
        else if (p->con.type == typebool)
            fprintf (fp,p->con.boolVal ? "false" : "true");
        else if (p->con.type == typefloat)
            fprintf (fp," %.4f", p->con.floatVal);
        else if (p->con.type == typestring)
            fprintf (fp," %s", p->con.strVal);
        break;

        //*********************************************************************************************************
    case typeId:
        fprintf (fp," %s", (p->id.label));
        break;
        //*********************************************************************************************************

    case typeOpr:
        switch (p->opr.oper)
        {

        //*********************************************************************************************************
        case WHILE:
            lbl1 = lbl++;
            push(lbl1, 0);
            fprintf (fp,"L%03d:\n", lbl1);
            fprintf(fp,"%d",rownum);
            rownum++;
            ex(p->opr.op[0], lbl1, lbl2,fp,1);
            fprintf (fp,"\n%d\tJZ",rownum);
            rownum++;
            int tempwhile = pop(2);
            fprintf (fp," Temp%d", tempwhile);
            lbl2 = lbl++;
            push(lbl2, 1);
            fprintf (fp," L%03d\n", lbl2);
            fprintf(fp,"%d",rownum);
            rownum++;
            ex(p->opr.op[1], lbl1, lbl2,fp,1);
            int popjmp = pop(0);
            fprintf (fp,"\tjmp\tL%03d\n", popjmp);
            fprintf(fp,"%d",rownum);
            rownum++;
            int popcon = pop(1);
            fprintf (fp,"L%03d:\n", popcon);
            fprintf(fp,"%d",rownum);
            rownum++;
            break;

            //*********************************************************************************************************

        case FOR:
            ex(p->opr.op[0], lbl1, lbl2,fp,1);
            lbl1 = lbl++;
            push(lbl1, 0);
            fprintf (fp,"L%03d:\n", lbl1);
            fprintf(fp,"%d",rownum);
            rownum++;
            ex(p->opr.op[1], lbl1, lbl2,fp,1);
            fprintf (fp,"%d\tJZ",rownum);
            rownum++;
            int tempfor = pop(2);
            fprintf (fp," Temp%d", tempfor);
            lbl2 = lbl++;
            push(lbl2, 1);
            fprintf (fp," L%03d\n", lbl2);
            fprintf(fp,"%d",rownum);
            rownum++;
            ex(p->opr.op[2], lbl1, lbl2,fp,1);
            int popjmpfor = pop(0);
            fprintf (fp,"\tjmp\tL%03d\n", popjmpfor);
            fprintf(fp,"%d",rownum);
            rownum++;
            int popconfor = pop(1);
            fprintf (fp,"L%03d:\n", popconfor);
            fprintf(fp,"%d",rownum);
            rownum++;
            break;

            //*********************************************************************************************************
        case DO:
            lbl1 = lbl++;
            push(lbl1, 0);
            fprintf (fp,"L%03d:\n", lbl1);
            fprintf(fp,"%d",rownum);
            rownum++;
            ex(p->opr.op[0], lbl1, lbl2,fp,1);
            ex(p->opr.op[1], lbl1, lbl2,fp,1);
            fprintf (fp,"\n%d\tJZ",rownum);
            rownum++;
            int tempdo = pop(2);
            fprintf (fp," Temp%d", tempdo);
            lbl2 = lbl++;
            push(lbl2, 1);
            fprintf (fp," L%03d\n", lbl2);
            fprintf(fp,"%d",rownum);
            rownum++;
            int popjmpdo = pop(0);
            fprintf (fp,"\tjmp\tL%03d\n", popjmpdo);
            fprintf(fp,"%d",rownum);
            rownum++;
            int popdo = pop(1);
            fprintf (fp,"L%03d:\n", popdo);
            fprintf(fp,"%d",rownum);
            rownum++;
            break;

            //*********************************************************************************************************
        case IF:
            ex(p->opr.op[0], lbl1, lbl2,fp,1);
            /* if else */
            lbl1 = lbl++;
            fprintf (fp,"\n%d\tJZ",rownum);
            rownum++;
            int temp = pop(2);
            fprintf (fp," Temp%d", temp);
            push(lbl1, 0);
            fprintf (fp,"  L%03d\n", lbl1);
            fprintf(fp,"%d",rownum);
            rownum++;

            ex(p->opr.op[1], lbl1, lbl2,fp,1);
            if (p->opr.op[1]->type != typeOpr || p->opr.op[1]->opr.oper != ELSE)
            {
                int lbl3 = pop(0);
                fprintf (fp,"L%03d:\n", lbl3);
                fprintf(fp,"%d",rownum);
                rownum++;
            }
            break;
            //*********************************************************************************************************

        case SWITCH:
            lbl2 = lbl++;
            push(lbl2, 0);
            if(p->opr.op[0]->type==typeOpr)
            {
            ex(p->opr.op[0], lbl1, lbl2,fp,1);
            tempexp = pop(2);
            switchexp=true;

            }
            else
                newp=p->opr.op[0];
            
            
            ex(p->opr.op[1], lbl1, lbl2,fp,1);
            int last = pop(0);
            fprintf (fp,"L%03d:\n", last);
            fprintf(fp,"%d",rownum);
            rownum++;

            break;

            //*********************************************************************************************************
        case '=':

            if (p->opr.op[1]->type == typeOpr)
            {
                ex(p->opr.op[1], lbl1, lbl2,fp,1);
                fprintf (fp,"\n");
                fprintf(fp,"%d",rownum);
                rownum++;
                fprintf (fp,"\tASSIGN\t %s ", p->opr.op[0]->id.label);
                int temp = pop(2);
                fprintf (fp," Temp%d", temp);
                tempexist = false;
            }
            else
            {
                fprintf (fp,"\tASSIGN\t %s ", p->opr.op[0]->id.label);
                ex(p->opr.op[1], lbl1, lbl2,fp,1);
            }
            fprintf (fp,"\n");
            fprintf(fp,"%d",rownum);
            rownum++;
            break;

            //*********************************************************************************************************

        default:
            if (p->opr.oper == ELSE)
            {
                ex(p->opr.op[0], lbl1, lbl2,fp,1);
                lbl2 = lbl++;
                push(lbl2, 1);
                fprintf (fp,"\tjmp\tL%03d\n", lbl2);
                fprintf(fp,"%d",rownum);
                rownum++;
                int lbl3 = pop(0);
                fprintf (fp,"L%03d:\n", lbl3);
                fprintf(fp,"%d",rownum);
                rownum++;
                ex(p->opr.op[1], lbl1, lbl2,fp,1);
                int lbl4 = pop(1);
                fprintf (fp,"L%03d:\n", lbl4);
                fprintf(fp,"%d",rownum);
                rownum++;
                break;
            }
            switch (p->opr.oper)
            {
                //*********************************************************************************************************
            case '+':
                expresion(p, "add", lbl1, lbl2, 2,fp);
                break;

                //*********************************************************************************************************
            case '-':
                expresion(p, "sub", lbl1, lbl2, 2,fp);
                break;

                //*********************************************************************************************************
            case '*':
                expresion(p, "mult", lbl1, lbl2, 2,fp);
                break;

                //*********************************************************************************************************
            case '/':
                expresion(p, "div", lbl1, lbl2, 2,fp);
                break;

                //*********************************************************************************************************
            case '~':
                expresion(p, "NEG", lbl1, lbl2, 1,fp);
                break;

                //*********************************************************************************************************
                //AND w OR fehom moshkela
            case '&':
                expresion(p, "And", lbl1, lbl2, 2,fp);
                break;
                //*********************************************************************************************************
            case '|':
                expresion(p, "OR", lbl1, lbl2, 2,fp);
                break;

                //*********************************************************************************************************
            case '<':
                expresion(p, "CompLT", lbl1, lbl2, 2,fp);
                break;

                //*********************************************************************************************************
            case '>':
                expresion(p, "compGT", lbl1, lbl2, 2,fp);
                break;

                //*********************************************************************************************************
            case COND_GREQ:
                expresion(p, "compGTEQ", lbl1, lbl2, 2,fp);
                break;

                //*********************************************************************************************************
            case COND_LSEQ:
                expresion(p, "compLTEQ", lbl1, lbl2, 2,fp);
                break;
                //*********************************************************************************************************

            case COND_NEQ:
                expresion(p, "compNEQ", lbl1, lbl2, 2,fp);
                break;
                //*********************************************************************************************************

            case COND_EQ:
                expresion(p, "compEQ", lbl1, lbl2, 2,fp);
                break;

                //*********************************************************************************************************

            case ';':
                ex(p->opr.op[0], lbl1, lbl2,fp,1);
                ex(p->opr.op[1], lbl1, lbl2,fp,1);
                break;

            //*********************************************************************************************************
            case CASE:;

                int first = pop(0);
                fprintf (fp,"L%03d:\n", first);
                fprintf(fp,"%d",rownum);
            rownum++;
                bool exp0 = false;
                if (p->opr.op[0]->type == typeOpr)
                {
                    ex(p->opr.op[0], lbl1, lbl2,fp,1);
                    exp0 = true;
                }

                int tempexp2;
                fprintf (fp,"\n");
                fprintf(fp,"%d",rownum);
            rownum++;
                fprintf (fp,"\t%s", "compEQ");
                if(switchexp)
                fprintf (fp," Temp%d", tempexp);
                else
                {
                    ex(newp, lbl1, lbl2,fp,1);
                }
                if (exp0)
                {
                    tempexp2 = pop(2);
                    fprintf (fp," Temp%d", tempexp2);
                }
                else
                    ex(p->opr.op[0], lbl1, lbl2,fp,1);

                fprintf (fp," Temp%d ", tempval);
                push(tempval, 2);
                tempval++;
                fprintf (fp,"\n");
                fprintf(fp,"%d",rownum);
                rownum++;
                fprintf (fp,"\tJZ");
                int tempswitch = pop(2);
                fprintf (fp," Temp%d", tempswitch);
                lbl2 = lbl++;
                push(lbl2, 0);
                fprintf (fp," L%03d\n", lbl2);
                fprintf(fp,"%d",rownum);
                rownum++;
                ex(p->opr.op[1], lbl1, lbl2,fp,1);
                break;

            //*********************************************************************************************************
            case CASE_JOIN:
                ex(p->opr.op[0], lbl1, lbl2,fp,1);
                ex(p->opr.op[1], lbl1, lbl2,fp,1);
                break;

            //*********************************************************************************************************
            case CONST:
                fprintf (fp,"\tDECCONST  ");
                ex(p->opr.op[0], lbl1, lbl2,fp,1);
                ex(p->opr.op[1], lbl1, lbl2,fp,1);
                fprintf (fp,"\n");
                fprintf(fp,"%d",rownum);
                rownum++;
                break;

            //*********************************************************************************************************
            case DEC:

                if (p->opr.nops == 1)
                {
                    fprintf (fp,"\tDECVAR  ");
                    ex(p->opr.op[0], lbl1, lbl2,fp,1);
                }
                else
                {   fprintf (fp,"\tDECVAR  ");
                    ex(p->opr.op[0], lbl1, lbl2,fp,1);
                    fprintf (fp,"\n");
                    fprintf(fp,"%d",rownum);
                    rownum++;
                    ex(p->opr.op[1], lbl1, lbl2,fp,1);
                }

                fprintf (fp,"\n");
                fprintf(fp,"%d",rownum);
                rownum++;
                break;

            default:
                break;
            }
        }
    }
    return 0;
     /* close the file*/  
   //
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
        printf ("\n\tSTACK is over flow");
    }
    else
    {
        // fprintf (fp,"\n /n %d /n \n",x);
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
        printf ("\n\t Stack is under flow\n");
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
void expresion(nodeType *p, char *string, int lbl1, int lbl2, int oper,FILE *fp)
{
    bool doneop0 = false;
    bool doneop1 = false;
    int valuepop0 = 0;
    int valuepop1 = 0;

    if (p->opr.op[0]->type == typeOpr)
    {

        ex(p->opr.op[0], lbl1, lbl2,fp,1);
        valuepop0 = pop(2);
        doneop0 = true;
        
    }
    if (p->opr.op[1]->type == typeOpr)
    {
        ex(p->opr.op[1], lbl1, lbl2,fp,1);
        valuepop1 = pop(2);
        doneop1 = true;
    }
    fprintf (fp,"\n");
    fprintf(fp,"%d",rownum);
    rownum++;
    fprintf (fp,"\t%s", string);
    if (!doneop0)
    {
        ex(p->opr.op[0], lbl1, lbl2,fp,1);
        fprintf (fp,"   ");
    }
    else
    {
        fprintf (fp," Temp%d", valuepop0);
    }
    if (oper == 2 && !doneop1)
        ex(p->opr.op[1], lbl1, lbl2,fp,1);
    else
    {
        fprintf (fp," Temp%d", valuepop1);
    }

    fprintf (fp," Temp%d ", tempval);
    tempexist = true;
    push(tempval, 2);
    tempval++;
    fprintf (fp,"\n");
    fprintf(fp,"%d",rownum);
    rownum++;
}
