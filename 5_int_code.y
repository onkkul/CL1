%{
   #include<stdio.h>
   char ch='a';
   char gencode(char ch1,char first,char op,char second);
%}

%union {
           char dval;
       }

%token <dval> NUM
%type <dval> E
%left '+' '-'
%left '*' '/'

%%
statement : E {printf("\nt = %c\nThree Address Code Generated..\n",$1);}
          ;

E : E '+' E {$$=gencode($$,$1,'+',$3);}
  | E '-' E {$$=gencode($$,$1,'-',$3);}
  | E '*' E {$$=gencode($$,$1,'*',$3);}
  | E '/' E {$$=gencode($$,$1,'/',$3);}
  | '(' E ')' {$$=$2;}
  | NUM {$$=$1;}
  ;
%%

char gencode(char ch1,char first,char op,char second)
{
        printf("\n%c = %c %c %c\n",ch,first,op,second);
        return ch++;
}
void main()
{
        yyparse();
}

