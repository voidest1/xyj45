// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// cast.c

#include <skill.h>
#include "/cmds/std/valid_kill.h";

#define SYNTAX "指令格式：cast <法术> [<参数>| on <目标>]\n";

inherit F_CLEAN_UP;

void destruct_flag(object me);

int main(object me, string arg)
{
   string spells, spl, trg, dest;
   object target;
   
   seteuid(getuid());

        if((int)me->query_temp("no_cast")==1)
           return notify_fail("你现在不能念咒文！\n");

   if( me->is_busy() )
     return notify_fail("( 你上一个动作还没有完成，不能念咒文。)\n");

   if( !wizardp(me) && environment(me)->query("no_magic") )
     return notify_fail("这里不准念咒文。\n");

   if( !arg ) return notify_fail(SYNTAX);
   if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
     target = present(trg, environment(me));
     if( !target ) target = present(trg, me);
     if (!target) target=find_object(trg);
     if( !target ) return notify_fail("找不到 " + trg + "。\n");
     
     if(!valid_kill(me,target)) return 0;

     if( userp(me) && userp(target) && 
         target->query_temp("netdead") )
        return notify_fail("对方正在断线中，不能对其施法。\n");
//   } else if (sscanf(arg, "%s to %s", spl, dest)==2) {
     
   } else {
     spl = arg;
     target = 0;
   }

   spl = replace_string( spl, " ", "_");

   if( stringp(spells = me->query_skill_mapped("spells")) ) {
           int nocast;
     notify_fail("你所学的法术中没有这种功能。\n");
     nocast=(int)SKILL_D(spells)->cast_spell(me, spl, target);
     //cast_spell should return an integer as the no_cast time.
     if (!nocast) 
       nocast=(int)SKILL_D("spells")->cast_spell(me, spl, target);
                if (nocast) {
                  me->set_temp("no_cast", 1);
       //each cast should return an integer which is
       //the no_cast time fot this cast.
       //also, in each cast, can set busy or no_move
       //time individually.   --mon 8/24/97
       call_out("destruct_flag", nocast, me);
       return 1;
     }
     return 0;
     }
     
   return notify_fail("你请先用 enable 指令选择你要使用的咒文系。\n");
}

void destruct_flag(object me)
{
     me->delete_temp("no_cast");
}

int help (object me)
{
        write(@HELP
指令格式：cast <咒文名称> [on <施咒对象>]
 
施法，你必需要指定<咒文名称>，<施咒对象>则可有可无。
在你使用某一个咒文之前，你必须先用 enable 指令来指定你要使用的咒文系。
 
注：如果你改变自己的咒文系，你原本蓄积的法力并不能直接转换过去，必须
    从 0 开始。
 
HELP
        );
        return 1;
}
