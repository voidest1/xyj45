// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   int lvl;

   if( me!=this_player(1) ) return 0;
   if( wiz_level(me) < wiz_level("(arch)") )
     return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
   if( !arg || arg=="" )
     return notify_fail("指令格式：wizlock <巫师等级>\n");

   if( sscanf(arg, "%d", lvl)!=1 ) lvl = wiz_level(arg);
   seteuid(getuid());
   if( LOGIN_D->set_wizlock(lvl) ) {
     write("Ok.\n");
     return 1;
   } else
     return notify_fail("上线权限设定失败。\n");
}

int help (object me)
{
        write(@HELP
指令格式: wizlock <巫师等级>
 
限制某个等级以下的使用者进入游戏。
其中巫师等级分别为 (immortal) (wizard) (arch) (admin), 若要取
消限制, 则输入 (player).
 
HELP
);
        return 1;
}
 