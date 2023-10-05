%{
#include <stdio.h>
int line_num = 1;
%}

%option noyywrap

DIGIT           [0-9]
LETTER          [a-zA-Z]
ID              {LETTER}({LETTER}|{DIGIT})*
NUM             {DIGIT}+
WHITESPACE      [ \t]
NEWLINE         \n

%%

{WHITESPACE}+   { /* Ignorar espaços em branco e tabulações */ }
{NEWLINE}       { line_num++; }
{NUM}           { printf("Token: NUM, Lexema: %s, Linha: %d\n", yytext, line_num); }
"if"            { printf("Token: IF, Lexema: %s, Linha: %d\n", yytext, line_num); }
"then"          { printf("Token: THEN, Lexema: %s, Linha: %d\n", yytext, line_num); }
"else"          { printf("Token: ELSE, Lexema: %s, Linha: %d\n", yytext, line_num); }
"end"           { printf("Token: END, Lexema: %s, Linha: %d\n", yytext, line_num); }
"repeat"        { printf("Token: REPEAT, Lexema: %s, Linha: %d\n", yytext, line_num); }
"until"         { printf("Token: UNTIL, Lexema: %s, Linha: %d\n", yytext, line_num); }
"read"          { printf("Token: READ, Lexema: %s, Linha: %d\n", yytext, line_num); }
"write"         { printf("Token: WRITE, Lexema: %s, Linha: %d\n", yytext, line_num); }
{ID}            { printf("Token: ID, Lexema: %s, Linha: %d\n", yytext, line_num); }
"+"             { printf("Token: '+', Lexema: %s, Linha: %d\n", yytext, line_num); }
"-"             { printf("Token: '-', Lexema: %s, Linha: %d\n", yytext, line_num); }
"*"             { printf("Token: '*', Lexema: %s, Linha: %d\n", yytext, line_num); }
"/"             { printf("Token: '/', Lexema: %s, Linha: %d\n", yytext, line_num); }
"="             { printf("Token: '=', Lexema: %s, Linha: %d\n", yytext, line_num); }
"<"             { printf("Token: '<', Lexema: %s, Linha: %d\n", yytext, line_num); }
"("             { printf("Token: '(', Lexema: %s, Linha: %d\n", yytext, line_num); }
")"             { printf("Token: ')', Lexema: %s, Linha: %d\n", yytext, line_num); }
";"             { printf("Token: ';', Lexema: %s, Linha: %d\n", yytext, line_num); }
":="            { printf("Token: ':=', Lexema: %s, Linha: %d\n", yytext, line_num); }
"{"[^}]*"}"    {  printf("Token: COMENTARIO, Lexema: %s, Linha: %d\n", yytext, line_num);}

.               { printf("Erro: Caractere não reconhecido: %s na linha %d\n", yytext, line_num); }

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo.tny\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    yyin = file;
    yylex();

    fclose(file);
    return 0;
}
