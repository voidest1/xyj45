// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
 // ji.c 祭法宝
 // created 7-4-97 pickle

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string targetname, fabaoname;
    object obj, *inv, target, obj2,old_env, fabao;
    int i, amount;
    mixed no_get;

    if( !wizardp(me) && environment(me)->query("no_magic") )
   return notify_fail("这里禁止祭法宝。\n");
    if( !arg ) return notify_fail("你要祭哪样法宝？\n");

    // Check if correct format is followed
    if( sscanf(arg, "%s on %s", fabaoname, targetname)>2 )
   return notify_fail("指令格式 : ji <法宝名称> [on <目标>]\n");

    // Check if both a fabao and a target is specified.
    // if so, then check 1. whether the player own's the fabao,
    // and 2. check whether the target is in the same environment.
    if( sscanf(arg, "%s on %s", fabaoname, targetname)==2 )
    {
   fabao=present(fabaoname, me);
   if(!fabao) return notify_fail("你没有 "+fabaoname+" 这样法宝。\n");
   target = present(targetname, environment(me));
   if (me->is_busy() && !fabao->query("no_busy"))
       return notify_fail("你上一个动作还没有完成，无暇分身祭法宝。\n");
   if(!target) return notify_fail("这里没有 " + targetname + "。\n");
   return fabao->ji(targetname);
   
}
    fabao=present(arg, me);
    if(!fabao) return notify_fail("你没有" + arg +"这样法宝。\n");
    if (me->is_busy() && !fabao->query("no_busy"))
   return notify_fail("你上一个动作还没有完成，无暇分身祭法宝。\n");

    return fabao->ji();
}
int help(object me)
{
    write(@HELP
指令格式 : ji <法宝名称> [on <目标>]

这个指令可以让你祭一项法宝。

HELP
        );
          return 1;
      }
