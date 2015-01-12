#include<stdio.h>
#include<math.h>       /* sqrt */

// DON'T ERASE THE VARIABLE AND FUNCTION
char grid[20][20];
void printGrid()
{
	int a,b;
	
	printf("\n\n   ");
	
	for(b=0; b<40; b++)
		if(b%2==0) printf(" "); else printf("%2d ",b/2);
	printf("\n");
	for(a=0; a<41; a++)
	{
		if(a%2==0) printf("   "); else printf("%2d ",a/2);
		for(b=0; b<40; b++)
		{
			if(a==0)
			{
				if(b==0) printf("%c%c",201,205);
				else if(b%2==0) printf("%c%c",203,205); else printf("%c%c",205,205);
			}
			else if(a==40)
			{
				if(b==0) printf("%c%c",200,205);
				else if(b%2==0) printf("%c%c",202,205); else printf("%c%c",205,205);
			}
			else
			{
			if(a%2==0)
				if(b==0) printf("%c%c",204,205);
				else if(b%2==0) printf("%c%c",206,205); else printf("%c%c",205,205);
			else 
				if(b%2==0) printf("%c ",186); else printf("%c ",grid[a/2][b/2]);
			}
		}
		if(a==0) printf("%c\n",187); 
		else if(a==40) printf("%c\n",188); 
			 else if(a%2==0) printf("%c\n",185); 
				  else printf("%c\n",186);
	}
	
	printf("\n\n");
}
// USE THIS SPACE TO WRITE YOUR FUNCTIONS

main()
{
	int a,b;
	
	for(a=0; a<20; a++)
		for(b=0; b<20; b++)
			grid[a][b] = ' ';
	
	printGrid();	// Remove this line after testing the program whether it is working or not


}
