%{
#include <iostream>
#define yyerror(s) cerr << "ERROR: " << s << endl
using namespace std;
int yylex(void);
%}


%union
{
    int in;
    // a) add double as dbl in the union
}

%token Newline
// b) declare type "Int" as "in" 
// c) declare type "Double" as "dbl"
%type <dbl> E T F

%%
start:
    expr
|   start expr
;

expr:
    E Newline {cout << $1 << endl;}
;

E:
    E '+' T {$$ = $1 + $3;}
|   E '-' T {$$ = /* d) ?*/ -  /* e) ?*/ ;}
|   T { /* f) ? */ = $1; }
;

T:
/*
* g) implement multiplication and division
*/
;

F:
    Int { $$ = static_cast<double>($1); }
|   Double { $$ = $1; }
|   '(' E ')' { /* h) ? */}
;

%%

#include "lex.yy.c"

int main()
{
    yyparse();
}
