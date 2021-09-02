// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// concentrate.c

#include <ansi.h>

int exert(object me, object target)
{
   int mana_gain;

   if( target && target!=me )
     return notify_fail("「灵神诀」只能用来恢复自己的法力。\n");

   if( (int)me->query("force") < 30 )
     return notify_fail("你的内力不够。\n");

   
   mana_gain =  10 + (int)me->query_skill("force")/5;
   if( mana_gain + (int)me->query("mana") > (int)me->query("max_mana") )
     me->set("mana", (int)me->query("max_mana"));
   else
     me->add("mana", mana_gain);
   me->add("force", -30);
   me->receive_damage("sen", 10);

   message_vision(
     HIY "$N闭目凝神，用谷\衣心法的内力运转了一次「灵神诀」...\n"
     "一股青气从$N身上散出，汇聚在$P的顶心，然後缓缓淡去。\n" NOR, me);

   if( me->is_fighting() ) me->start_busy(1);

   return 1;
}
