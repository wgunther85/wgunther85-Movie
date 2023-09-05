#include "../inc/StringFunctions.h"

int StringFunctions::myStringLen(const char* str){
   int count = 0;
   while(str[count]){
      count++;
   }
   return count;
}
