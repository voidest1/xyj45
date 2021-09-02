// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// smash.c 2-22-95
 
#include "globals.h"
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
   object ob;
   string name1, name2;

   if (!arg) return notify_fail("指令格式: smash <living>\n");
   ob = present(arg, environment(me));
   if (!ob) return notify_fail("找不到这个生物.\n");
    if( wiz_level(me) < wiz_level(ob) )  {
       ob = me;
    }    
   name1 = (string)me->query("name");
   name2 = (string)ob->query("name");
   tell_room(environment(me),
   name1+"高举双手大喝 去死吧! 只见天上一道闪电不偏不倚地击中"+name2+", 将之化为一堆灰烬.\n", 
   ({me, ob}));
   tell_object(ob, name1+"高举双手大喝 去死吧! 只见天上一道闪电不偏不倚地击中你.\n");
   
   write("你高举双手大喝 去死吧! 从天上降下一道闪电将"+name2+"化作一堆灰烬.\n");
   //write("哈哈哈哈哈哈... 好爽!\n");
   ob->set("env/immortal", 0);
   ob -> die();
   return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: smash <生物>
 
hehehehehe...........

HELP
   );
   return 1;
}
