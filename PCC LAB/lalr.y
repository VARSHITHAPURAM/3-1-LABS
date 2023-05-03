%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%{
void yyerror(const char *s);
int yylex();
%}
%token NUMBER
%left '+' '-'
%left '*' '/'

%%

program:
    expr        { printf("%d\n", $1); }
;

expr:
    expr '+' expr   { $$ = $1 + $3; }
|   expr '-' expr   { $$ = $1 - $3; }
|   expr '*' expr   { $$ = $1 * $3; }
|   expr '/' expr   { $$ = $1 / $3; }
|   '(' expr ')'   { $$ = $2; }
|   NUMBER          { $$ = $1; }
;

%%

int main(int argc, char *argv[]) {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

