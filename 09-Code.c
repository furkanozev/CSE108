#include <stdio.h>
#include <string.h>
#define WORD_SIZE 6
#define WORD_COUNT 9

void spell_checking(char* p_text, size_t p_text_len, char* dict, size_t dict_len)
{
	int i=0,k=0,j=0,t=0,count=0,z=0;
    char dict_words[WORD_COUNT][WORD_SIZE];
    char temp_word[WORD_SIZE];
    for(i=0; i <= p_text_len; i++)
    {
    	if(p_text[i] != ' ' || p_text[i] != '\n' || p_text[i] != '\t')
    	{
    		temp_word[k] = p_text[i];
    		k++;
    	}
    	else
    	{
    		for(j=0; j<=dict_len; j++)
    		{
    			for(t=0; t<=6; t++)
    			{
    				count = 0;
    				if(temp_word[t] == dict_words[j][t])
    				{
    					count++;
    				}
    			}
    			if(count >= 3)
    			{
    				for(z=0;z<6;z++)
    				{
    					printf("%c",dict_words[j][z]);
    				}
    			}
    		}
    		k=0;
    	}
    	if(k==0 && count < 3)
    	{
    		for(z=0;z<6;z++)
    		{
    			printf("%c",temp_word[z]);
    		}
    	}	
    }
    
}

int word_counter(char* text, size_t text_len, char separator)
{
    int i=0,counter=0, k;
    for(i=0; i<=text_len; i++)
    {
    	if(text[i] != separator && text[i+1] == separator)
    	{
    		counter++;
    		k=i;
    	}
    }
    if(k != i)
    {
      counter++;
    }
    printf("\nWord:%d",counter);
}

void delete_numbers(char* text, size_t text_len)
{
    int i;
    for(i=0; i<=text_len; i++)
    {
    	if(!(text[i] >= '1' && text[i] <= '9'))
    	{
    		printf("%c",text[i]);
    	}
    }
}

void correct_misspell(char* text, size_t text_len)
{
    int i;
    int t = 'A' - 'a';
    for(i=0; i<=text_len; i++)
    {
    	if(!(text[i] >= '1' && text[i] <= '9'))
    	{
	    	if(text[i] == ',')
	    	{
	    		printf("%c",text[i]);
	    		i++;
	    		if(text[i] != ' ')
	    		{
	    			printf(" ");
	    			printf("%c",text[i]);
	    		}
	    		else
	    		{
	    			printf("%c",text[i]);
	    			i++;
	    			printf("%c",text[i]);
	    		}
	    	}
	    	else if(text[i] == '.')
	    	{
	    		printf("%c",text[i]);
	    		i++;
	    		if(text[i] != ' ')
	    		{
	    			printf(" ");
	    			printf("%c",text[i]);
	    		}
	    		else
	    		{
	    			printf("%c",text[i]);
	    			i++;
	    		}
	    		if(text[i] >= 'a' && text[i] <= 'z')
	    		{
	    			printf("%c",text[i]+t);
	    		}
	    		else
	    		{
	    			printf("%c",text[i]);
	    		}
	    	}
	    	else
	    	{
	    		printf("%c",text[i]);
	    	}
	    }
    }
}

int main()
{
char* string_part1="In a h2141ole 15125i12n the ground there 12516lived a hobbit. not326236 a na236sty,dirty, we568t ho967le,filled w679679ith the ends o6679f worm96979679s697967 and an67996796 oozy smell, no474584r yet 45845a dry, bare, sandy hol45824e with nothing in it4288 to sit down on or to eat: 452842it was a hobbit-hole,258 and that means comfort.It h25482ad a perfectly round door 45824like a porthole, painted green, with a shiny yello45828w brass knob in4582 the exact middle.the door opened on t2458428o a tube-shaped4585 hall like a tunnel: a 24848very comfortable tun2458nel without smoke, with panelled wall4582824s, and floors tiled and carpeted, provided 45822with polished chairs, a1346nd lots and lots of84845 pegs for hats and coats-the23525 hobbit was fond of visitors.";
char* string_part2="The tunner wound on and on, going fairly but not quite straight into the side of the hill. The Hill, as all the people for many miles round called it and many little round doors opened out of it, first on one side and then on another. No going upstairs for the habbit bedrooms, bathrooms, cellra, pantries, wardrobes, he had whole rooms devoted to cloths, kitchens, dining-rooms, all were on the same floor, and indd on the same pasage.";
char* dict="hobbit,tunnel,dragon,farmer,clothe,indeed,mobile,yellow,cellar,";
size_t s_p1_len=strlen(string_part1);
size_t s_p2_len=strlen(string_part2);
size_t dict_len=strlen(dict);

//delete_numbers(string_part1, strlen(string_part1));
//correct_misspell(string_part1, strlen(string_part1));
//word_counter(string_part2, strlen(string_part2), ',');
spell_checking(string_part2, strlen(string_part2), dict, strlen(dict));

}
