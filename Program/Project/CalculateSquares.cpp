//-------------------------------------------------------------------------
// FileName: test.cpp : Defines the entry point for the console application.
// Author: Tran Minh Long
//-------------------------------------------------------------------------


#include <stdlib.h>
#include "Number.h"

static int countLine;
#define ENTER 10
#define END_PROGRAM 'q'
#define RE_TEST 'r'

void appenData(char* dataDes, const char* dataSource)
{
   size_t lenght = strlen(dataSource);
   strncat(dataDes, dataSource, lenght);
}

//-------------------------------------------------------------------------------------------------
// FuntionName: readCharacter
// Purpose: read each character input from stdin, then add it to number object
//          case charater is ' ' => build number.
//          case charater is '\n' => Calculate a sum of squares for Line, then loop for other Line
//          case charater is 'q' => end of test.
//          Other case will be reject.
//--------------------------------------------------------------------------------------------------
bool readCharacter( Number& num, char*& buff, char& sign, bool& isInputIncorrect )
{
   char c = getchar();
   if( c == ENTER )
   {
      putc('\n',stdout);
   }
   else if( c != END_PROGRAM )
   {
      putc(c,stdout);
   }

   if( (c >= '0' && c <= '9') || c == ENTER || c == END_PROGRAM || c == '-' || c == ' ')
   {
      if(c == END_PROGRAM)
      {
         sign = END_PROGRAM;
         return true;
      }
      else
      {
         if( c != ' ' && c != ENTER )
         {
            num.setListCharacter(c);
         }
         else
         {
            bool ret = num.setNumber();
            if(ret)
            {
               countLine += num.getNumber() * num.getNumber();
               num.reset();
            }
            else
            {
               num.reset();
               countLine = 0;
               isInputIncorrect = true;
               return true;
            }

            if( c == ENTER )
            {
               char buf[10];
               sprintf(buf,"%d\n",countLine);
               appenData(buff,buf);
               countLine = 0;
            }
         }

         readCharacter(num, buff, sign, isInputIncorrect);
      }
   }
   else
   {
      num.reset();
      countLine = 0;
      isInputIncorrect = true;
      return true;
   }
}

int readData(char*& buff, Number& num, bool& isInputIncorrect)
{
   char c;
   if( readCharacter(num, buff, c, isInputIncorrect) )
   {
      if(c == END_PROGRAM || isInputIncorrect)
      {
         return 0;
      }
      readData(buff, num, isInputIncorrect);
   }
}

void commentOfRequirement()
{
   printf("Calculate a sum of squares of some integers in Line \n");
   printf("Excepting negatives                                 \n");
   printf("End of line must be '\\n' (Enter) character         \n");
   printf("Number input is less than 100                       \n");
   printf("Press q to show output                              \n");
   printf("After output:                                       \n");
   printf("Press r to continous test                           \n");
   printf("Press any button to quit                            \n");
   printf("----------------------------------------------------\n");
   printf("Input:\n");
}

void test(char*& buff, Number& num)
{
   bool isInputIncorrect = false;
   commentOfRequirement();
   readData(buff, num, isInputIncorrect);
   if( isInputIncorrect )
   {
      printf("\nYour input data is wrong.\n");
      printf("Press r to continous test. \n");
      printf("Or press any button to quit.  \n");
   }
   else
   {
      printf("----------------------------------------------------\n");
      printf("Output:\n");
      printf("%s",buff);
   }

   char c = getchar();
   if( c == RE_TEST )
   {
      memset(buff,0,1024);
      if(system("CLS")) system("clear");
      test(buff, num);
   }
   else
   {
      return;
   }
}

int main()
{
   char* buff = (char*) malloc(1024);
   memset(buff,0,1024);
   Number num;
   system("stty -icanon -echo");
   test(buff, num);
   system("stty icanon echo");
   return 0;
}
