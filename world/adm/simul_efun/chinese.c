// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

string chinese_number(int i)
{
   return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
   return CHINESE_D->chinese(str);
}

int is_chinese(string str)
{
   return 1;
   if( strlen(str)>=2 && (str[0] & 0x80)) return 1;
   return 0;
}
