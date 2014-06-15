//-----------------------------------------------------------------------------------
// ClassName: number
// Purpose: with each character input from stdin will be built to number
//          This class will help us build all character seperator by ' ' to number
//------------------------------------------------------------------------------------
#ifndef NUMBER_H
#define NUMBER_H

#include <stdio.h>
#include <string.h>

class Number
{
private:
   char m_lCharacter[3];
   int m_Value;
   int m_countChar;

public:
   void setListCharacter(char c);
   bool setNumber();
   void reset();
   int getNumber();

   Number();
};

#endif
