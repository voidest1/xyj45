// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
   object ob, *inv;
   int i, count;

   if( !arg ) return notify_fail("你要装备什么武器？\n");

   if(arg=="all") {
     inv = all_inventory(me);
     for(count=0, i=0; i<sizeof(inv); i++) {
        if( inv[i]->query("equipped") ) continue;
        if(do_wield(me, inv[i]) ) count ++;
     }
     write("Ok.\n");
     return 1;
   }

   if( !objectp(ob = present(arg, me)) )
     return notify_fail("你身上没有这样东西。\n");

   if( ob->query("equipped") )
     return notify_fail("你已经装备着了。\n");

   return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
   string str;

    if( ob->query("owner_id") && ob->query("owner_id") != getuid(me) )   {
     destruct(ob);
     return notify_fail("下次别乱偷别人的东西。\n");
   }

   if( ob->wield() ) {
     if( !stringp(str = ob->query("wield_msg")) )
        str = "$N装备$n作武器。\n";
     message_vision(str, me, ob);
     return 1;
   } else
     return 0;
}

int help(object me)
{
   write(@HELP
指令格式：wield|zhuangbei <装备名称>
 
这个指令让你装备某件物品作武器, 你必需要拥有这样物品.
 
HELP
    );
    return 1;
}
