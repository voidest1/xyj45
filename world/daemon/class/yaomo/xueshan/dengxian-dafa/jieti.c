// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

// jieti.c 天魔解体大法。

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg;
   int success, ap, dp;

   if( (string)me->query("class") != "yaomo" )
     return notify_fail("只有妖魔才能施展天魔解体大法。\n");

   if( !target ) target = offensive_target(me);

   if( !target
   || !target->is_character()
   || target->is_corpse()
   || target==me)
     return notify_fail("你要对谁施展天魔解体大法？\n");

   if((int)me->query("mana") < 100 || (int)me->query("max_mana") < 100 )
     return notify_fail("你的法力不够，不能有效施展天魔解体大法！\n");

   if((int)me->query("force") < 50 || (int)me->query("max_force") < 50 )
     return notify_fail("你的内力不够，不能有效施展天魔解体大法！\n");

   if((int)me->query("sen") < 100 || (int)me->query("sen") < (int)me->query("max_sen")/2 )
     return notify_fail("你无法集中精力施展天魔解体大法！\n");

   if( (int)me->query("combat_exp") < (int)target->query("combat_exp")/10  )
     return notify_fail("对方比你强太多了，还是别送死吧！\n");
   //here, we do not allow that a too weak player trys this on 
   //a much stronger player. this is to prevent statistically possible 
   //but unreasonable results from happenning. 

   if( random(me->query("max_mana")) < 50 ) {
     write("你失败了！\n");
     return 1;
   }

   msg = HIC
"$N口中念了几句咒文，双手捧住脑袋，仰天发出一声悲嘶！\n\n忽然间$N将自己舌头狠命一咬，一道血雾向$n喷了过去！\n" NOR;

   success = 1;
   ap = me->query_skill("spells");
   ap = ap * ap * ap /10 ;
   ap += (int)me->query("combat_exp");
   ap = 4*ap; //this is for 拼命 so easier.
   dp = target->query("combat_exp");
   if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

   ap = (int)me->query("max_mana");
   dp = (int)target->query("max_mana");
   if( ap < random(dp) ) success = 0;
//here we compared max_mana.
//if the attacher has half of the max_mana of the target, 
//he has 50% chance to kill his target, which is reasonable.

   if(success == 1 ){//now both die.
     msg +=  HIR "结果$n被血雾罩住，顿时发出一声惨叫！\n而$N也身子一瘫，倒在地上。\n" NOR;
     message_vision(msg, me, target);

     target->kill_ob(me);
     me->kill_ob(target);
     //to produce killing messages.

     me->add("max_mana", -100);
     me->add("max_force", -50);
     me->save();
     //successed, attacker lost 100 max_fali and 50 max_neili.
     
     target->receive_wound("sen", (int)target->query("max_sen")+1, me);
     target->receive_wound("kee", (int)target->query("max_kee")+1, me);
     COMBAT_D->report_status(target);
     //target die here.

     me->receive_wound("sen", (int)me->query("max_sen")+1, target);
     me->receive_wound("kee", (int)me->query("max_kee")+1, target);
     COMBAT_D->report_status(me);
     //attacker die here.

   }
       
   else {
     msg +=  HIR "结果血雾被$n法力反激，反而罩住了$N！\n$N长叹一声，身子一瘫，倒在地上。\n" NOR;
     message_vision(msg, me, target);

     target->kill_ob(me);
     me->kill_ob(target);
     //to produce killing messages.

     me->add("max_mana", -50);
     me->add("max_force", -25);
     me->save();
     //failed, attacker lost 50 max_fali and 25 max_neili.
     
     me->receive_wound("sen", (int)me->query("max_sen")+1, target);
     me->receive_wound("kee", (int)me->query("max_kee")+1, target);
     COMBAT_D->report_status(me);
     //attacker die here.
   } 

   return 3+random(5);
}

