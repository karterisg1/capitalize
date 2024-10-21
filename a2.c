#include <stdio.h>

#define PRINTTAB(X) {int i; for (i=0; i < (X); i++) putchar('\t');}
#define EATSPACE()  {while((c=getchar()) == ' ' || c == '\t' || c == '\n');}

int main()
{
    int c, t;
    int tab = 0; 	/* tab level */
    int f = 0;
    int fl = 0;
    int q = 0;
    int p = 0;
    int forl = 0;
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\'' || c == '\"')
		{
			int x = 0;
			int hold = c;
			
			q = 1;
			if (f != 0)
			{
				putchar(' ');
				f = 0;
			}
			while (c != EOF)
			{			
				putchar(c);
				t = c;
				c = getchar();
				if (c == EOF)
				{
					return 0;
				}
				if (c == '\\') x++;
				else if (c ==  hold && (t != '\\' || x % 2 == 0))
				{	
					putchar(c);
					break;
				}
				else
				{
					x = 0;
				}
			}
		}
		else if (c == '#')
		{
			f = 0;
			q = 1;
			while (c != EOF)
			{
				putchar(c);
				c = getchar();
				if (c == EOF)
				{
					return 0;
				}
				if (c == '\n')
				{
					EATSPACE();
					if (c != EOF)
					{
						putchar('\n');
						if (c == '#')
						{
							PRINTTAB(0);
						}
						else if (c != '}')
						{
							PRINTTAB(tab);
						}
					}
					ungetc(c, stdin);	
					break;		
				}	
			}
		}
		else if (c == ' ' || c == '\t' || c == '\n')
		{
			q = 1;
			f++;
		}
		else if (c == '{' || c == '}' || c == ';')
		{
			q = 1;
			f = 0;
			if (c == '{')
			{			
				if (forl == 2)
				{
					fl = 0;
					forl = 0;
				}
				tab++;
				putchar(' ');
				putchar(c);
			}
			else if (c == '}')
			{
				tab--;
				PRINTTAB(tab);
				putchar(c);
			}
			else
			{
				putchar(c);
				if (forl == 1)
				{		
					continue;
				}
				if (forl == 2)
				{
					fl = 0;
					forl = 0;
				}
			}
			EATSPACE();
			if (c != EOF)
			{
				putchar('\n');
				if (c == '#')
				{
					PRINTTAB(0);
				}
				else if (c != '}')
				{
					PRINTTAB(tab);
				}
				ungetc(c, stdin);	
			}			
		}
		else 
		{
			if (f != 0)
			{
				putchar(' ');
				f = 0;
			}
			putchar(c);
			if (q == 1)
			{
				if (fl == 0 && c == 'f')
				{
					fl = 1;
				}
				else if (fl == 1 && c == 'o')
				{
					fl = 2;
				}
				else if (fl == 2 && c == 'r')
				{
					fl = 3;
				}
				else if (fl == 3 && c == '(')
				{
					p = 1;
					forl = 1;
					fl = 4;
				}
				else if (fl == 4 && c == '(')
				{
					p++;
				}
				else if (fl == 4 && c == ')')
				{
					p--;
					if (p == 0)
					{
						forl = 2;
						fl = 0;
						q = 1;
					}
				}
			}
		}
	}
	return 0;
}
