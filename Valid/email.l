/*lex code to accept a valid email */
%{ 
int flag = 0; 
%} 
%%
[a-z.0-9_]+"@"[a-z]+".com" { printf("valid");} 
%% 
main() 
{
	printf("enter mail:\n");
	yylex(); 
} 
int yywrap()
{
	return 1;
}