// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat feb 4 1998

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object who, string arg)
{
  object me;
  object where = environment(who);
  object rider;
  object ridee;

  if (! arg ||
      ! where ||
      ! (me = present(arg,where)) ||
      ! me->query("ride/msg"))
    return notify_fail ("你想骑什么？\n");

  ridee = who->query_temp("ridee");
  if (ridee &&
      environment(ridee) != environment(who))
   ridee = 0;

  if (ridee)
    return notify_fail ("你已经"+ridee->query("ride/msg")+"在"+ridee->name()+"上了！\n");

  rider = me->query_temp("rider");
  if (rider &&
      environment(rider) != environment(me))
   rider = 0;

  if (rider)
    return notify_fail (me->name()+"上已有人了！\n");

  message_vision ("$N潇洒地一个纵身，稳稳地"+me->query("ride/msg")+"在$n上！\n",who,me);
  me->set_temp("no_return",1);
  me->set_temp("rider",who);
  who->set_temp("ridee",me);
  me->move(where);
  who->set_temp("ride/dodge",me->query("ride/dodge"));
  who->add_temp("apply/dodge",me->query("ride/dodge"));
  return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : mount <坐骑名称>

这个指令可以让你骑到坐骑身上。

HELP
);
  return 1;
}
