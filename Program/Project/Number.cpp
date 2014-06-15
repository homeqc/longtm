//-------------------------------------------------------------------------
// FileName: Number.cpp : Implement all method in Number class.
// Author: Tran Minh Long
//-------------------------------------------------------------------------

#include "Number.h"

Number::Number()
{
   m_countChar = 0;
   memset(&m_lCharacter,0,3);
}

bool Number::setNumber()
{
   if(m_countChar == 1)
   {
      if(m_lCharacter[0] >= '0' && m_lCharacter[0] <= '9')
      {
         m_Value = m_lCharacter[0] - '0';
      }
      else
      {
         m_Value = 0;
      }
   }
   else if(m_countChar == 2)
   {
      if( (m_lCharacter[0] >= '0' && m_lCharacter[0] <= '9') &&
          (m_lCharacter[1] >= '0' && m_lCharacter[1] <= '9') )
      {
         int t1 = m_lCharacter[0] - '0';
         int t2 = m_lCharacter[1] - '0';
         m_Value = t1*10 + t2;
      }
      else
      {
         m_Value = 0;
      }
   }
   else if(m_countChar == 3)
   {
      if( (m_lCharacter[0] == '0') &&
          (m_lCharacter[1] >= '0' && m_lCharacter[1] <= '9') &&
          (m_lCharacter[2] >= '0' && m_lCharacter[2] <= '9') )
      {
         int t1 = m_lCharacter[1] - '0';
         int t2 = m_lCharacter[2] - '0';
         m_Value = t1*10 + t2;
      }
      if( (m_lCharacter[0] == '-') &&
          (m_lCharacter[1] >= '0' && m_lCharacter[1] <= '9') &&
          (m_lCharacter[2] >= '0' && m_lCharacter[2] <= '9') )
      {
         m_Value = 0;
      }
      else if( m_lCharacter[0] == '1' && m_lCharacter[1] == '0' || m_lCharacter[2] == '0' )
      {
         m_Value = 100;
      }
      else
      {
         return false;
      }
   }

   return true;
}

void Number::setListCharacter(char c)
{
   m_lCharacter[m_countChar] = c;
   ++m_countChar;
}

void Number::reset()
{
   memset(&m_lCharacter,0,3);
   m_Value = 0;
   m_countChar = 0;
}


int Number::getNumber()
{
   return m_Value;
}
