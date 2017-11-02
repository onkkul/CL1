%{
        #include"y.tab.h"
%}

%%
[0-9]+ {yylval.dval=yytext[0]; return NUM;}
\n {return 0;}
. {return yytext[0];}
%%


