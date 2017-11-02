%{
// header files 
#include<stdio.h>
#include<stdlib.h>
#include"string.h"

//Creating Stucture
typedef struct myStruc
{
	int index ;
	char symbol[50];
}structure;

//Creating different structure objects
structure preProcessors[10],keywords[10],variables[10],operators[10],numerics[10],specials[10];

int i =0, ipp=0, ikw=0, ivar=0, iop=0,in=0,isp=0;

char buffer[30];

%}


preProcessor "#include<"{variable}*">"

keyword	 "int"|"float"|"double"|"char"|"void"|"if"|"else"|"do"|"while"|"for"|"break"|"continue"|"switch"|"case"|"default"|"struct"|"using"|"return"|"namespace"|"std"

variable [A-Za-z_][A-Za-z0-9_$]*

operator "{"|"}"|"["|"]"|"("|")"|"<"|">"|"="|"=="|"<="|">="|"-"|"+"|"*"|"%"|"/"|"<<"|">>"

numeric [0-9]+

sp ","|";"

%%

{preProcessor} { 
	ipp = insert(yytext,preProcessors,ipp);
}
{keyword} {
	ikw = insert(yytext,keywords,ikw);
}
{variable} {
	ivar = insert(yytext,variables,ivar);
}
{operator} {
	iop = insert(yytext,operators,iop);	
}
{numeric} {
	in = insert(yytext,numerics,in);
}

{sp} {
	isp = insert(yytext,specials,isp);
}
%%

int search(char var[10],structure array[],int counter)
{
	int i;
	for(i=0;i<=counter;i++)
	{
		if(strcmp(array[i].symbol , var)==0)
			return( 1 );
	}
return( 0 );
}

int insert(char var[50],structure array[],int counter)
{
	if( search(var,array,counter) != 1)
	{
		array[counter].index = counter;
		strcpy(array[counter].symbol,var);
		counter++;
	}
	return counter;
}

int main()
{
	yylex();
}
printf("\nSYMBOL TABLE:\n");

printf("INDEX\t\tSYMBOL\t\tNATURE\n");

for(i=0;i<ipp;i++)
	printf("\n%d\t%s\t%s",preProcessors[i].index,preProcessors[i].symbol," is a Preprocessor.\n");
printf("\n----------------------");

for(i=0;i<ikw;i++)
	printf("\n%d\t%s\t%s",keywords[i].index,keywords[i].symbol," is a Keyword.\n");
printf("\n----------------------");

for(i=0;i<ivar;i++)
	printf("\n%d\t%s\t%s",variables[i].index,variables[i].symbol, " is a Variable.\n");
printf("\n----------------------");

for(i=0;i<iop;i++)
	printf("\n%d\t%s\t%s",operators[i].index,operators[i].symbol, " is a Operator.\n");
printf("\n----------------------");

for(i=0;i<in;i++)
	printf("\n%d\t%s\t%s",numerics[i].index,numerics[i].symbol, " is a Numeric Constant.\n");
printf("\n----------------------");

for(i=0;i<isp;i++)
	printf("\n%d\t%s\t%s",specials[i].index,specials[i].symbol, "is a Sp. Symbol.\n");

return 0;
}

int yywrap()
{
	return(1);
}



