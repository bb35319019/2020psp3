#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int start,pos,text_len=strlen(text),key_len=strlen(key),correct;
    for(start = 0; start <= (text_len - key_len); start++)
    {
        for(pos=0, correct = 0; pos <= key_len; pos++)
        {
             if(text[start + pos] == key[pos])
             {
                correct++;
             }
             if(correct == key_len)
             {
                 return text + start;
             }
        }
    }
    return NULL;
    //  ここを実装する

}

char* BMSearch(char text[], char key[])
{
   
   char table[ALPHABET_LEN];
   int n=0, index = strlen(key)-1, key_len = strlen(key), pos = key_len-1, index_before;

   while(n <= ALPHABET_LEN)
   {
       table[n] = key_len;
       n++;
   }

   int text_len = strlen(text);
   n=0;

   while(n < key_len)
   {
       table[(int)key[n]]  =key_len - 1 - n;
       n++;
   }
   index_before = index;    
   while(index <= text_len - 1)
   {
       while(pos >= 0)
       {
           if(text[index] == key[pos])
           {
               if(pos == 0)
               {
                   return text + index;
               }
               index--;
               pos--;
           }
           else
           {
               pos = key_len - 1;
               break;
           }
       }
       index = index + table[(int)text[index]];
       if(index_before > index || index_before == index)
       {
           index = index_before + 1;
       }
   }
   return NULL;
    //  ここを実装する

}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}