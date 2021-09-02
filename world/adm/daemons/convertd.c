// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
/* rewritten by Snowcat */

#pragma optimize

inherit F_DBASE;

#define SC_DO_SINGLE     0
#define SC_DO_ALL     1
#define SC_DO_ALL_BUT_SYMBOLS   2
/* Code mapping tables. */


string input (string str, object me)
{
    return str;
}
string output (string str, object me)
{
    return str;
}
void create()
{
   seteuid(getuid());
   set("name", "GB BIG5 converter");
   set("id", "GB BIG5 converter");
}