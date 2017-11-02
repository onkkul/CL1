%{
#include <stdio.h>
#include <stdlib.h>
%}
%token ID NUM SWITCH CASE DEFAULT BREAK LE GE EQ NE OR AND ELSE
%left '!'
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%right UMINUS
%right '='
%%

S: ST {printf("Input accepted.\n");exit(0);};
ST:SWITCH '(' ID ')' '{' B '}';
B:C|C D;
C:C C|CASE NUM ':' E ';'
     |BREAK ';';

D:DEFAULT':'E';'BREAK';';
E   : ID'='E
    | E'+'E
    | E'-'E
    | E'*'E
    | E'/'E
    | E'<'E
    | E'>'E
    | E LE E
    | E GE E
    | E EQ E
    | E NE E
    | E OR E
    | E AND E
    | ID
    | NUM
    ;

%%

#include "lex.yy.c"

main()
{
printf("Enter the exp: ");
yyparse();
}
