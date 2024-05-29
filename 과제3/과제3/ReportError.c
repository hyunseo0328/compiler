#include <stdio.h>
#include <stdlib.h>
#include "glob.h"
// 라인 넘버 변수는 lineno , glob.h에 정의되어 있음
// ErrorType 도 glob.h에 정의

extern char *yytext;

yyerror(char* s)
{

}

void ReportError(ErrorType err)
{
	switch(err)
	{
	case noerror: 
		break;
  	case digit_ident:
		cErrors++;
		printf("line %6d          ERROR!!			  %-10s		start with digit\n", lineno, yytext);
		break;
	case long_ident:
		cErrors++;
		printf("line %6d          ERROR!!			  %-13s	 	too long identifier\n", lineno, yytext);
		break;
	case ill_symbol:
		cErrors++;
		printf("line %6d          ERROR!!			  %-5c		illegal symbol\n", lineno, yytext[0]);
		break;
	case over_st:
		cErrors++;
		printf("\nError : OVERFLOW in ST\n");
		printf("==================================================\n");
		exit(0);
		break;
	case missing_semi:
		cErrors++;
		printf("line %6d          ERROR!!			  missing semicolon\n", lineno-1);
		break;
	case missing_lparen:
		cErrors++;
		printf("line %6d          ERROR!!			  no left parenthesis\n", lineno);
		break;
	case missing_lcurly:
		cErrors++;
		printf("line %6d          ERROR!!			  no left curly bracket\n", lineno);
		break;
	case missing_lsquare:
		cErrors++;
		printf("line %6d          ERROR!!			  no left square bracket\n", lineno);
		break;
	case missing_rparen:
		cErrors++;
		printf("line %6d          ERROR!!			  no right parenthesis\n", lineno);
		break;
	case missing_rcurly:
		cErrors++;
		printf("line %6d          ERROR!!			  no right curly bracket\n", lineno);
		break;
	case missing_rsquare:
		cErrors++;
		printf("line %6d          ERROR!!			  no right square bracket\n", lineno);
		break;

	case missing_comma:
		cErrors++;
		printf("line %6d          ERROR!!			  missing comma\n", lineno);
		break;
	case missing_funcheader:
		cErrors++;
		printf("line %6d          ERROR!!			  no function header\n", lineno);
		break;
	case declaring_err:
		cErrors++;
		printf("line %6d          ERROR!!              	wrong declaration\n", lineno);
		break;
	case missing_condition:
		cErrors++;
		printf("line %6d          ERROR!!              	missing condition\n", lineno);
		break;
	case wrong_assign:
		cErrors++;
		printf("line %6d          ERROR!!              	wrong assignment\n", lineno);
		break;
	case missing_operand:
		cErrors++;
		printf("line %6d          ERROR!!              	missing operand\n", lineno);
		break;
		
	}
}
