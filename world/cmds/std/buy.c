// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// buy.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string item, targ = "";
   object owner;
   int i, price, afford;
   object* inv;

    if( this_player()->is_busy() )
        return notify_fail("你现在正忙着呢。\n");

   if( !environment(me) )
     return notify_fail("你要跟谁买东西？\n");

   if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 ) {
     inv = all_inventory(environment(me));
     i = sizeof (inv);
     while (i--) {
       if (inv[i]->is_vendor()) {
         item = arg;
         targ = inv[i]->query("id");
         break;
       }
     }
     if (targ == "")
       return notify_fail("指令格式：buy <某物> from <某人>\n");
   }

   if( !objectp(owner = present(targ, environment(me))) )
     return notify_fail("你要跟谁买东西？\n");

   if( userp(owner) ) {
     message_vision("$N想向$n购买「" + item + "」。\n", me, owner);
           notify_fail("对方好像不愿意跟你交易。\n");
     return 1;
   }

   if( (price = owner->buy_object(me, item)) == -1 ) return 1;
   if( price < 1 ) return 0;

   if( afford = me->can_afford(price) ) {
           if( afford==2 ) 
        return notify_fail("你没有足够的零钱，而银票又没人找得开。\n");

//     me->start_busy(1);
//     owner->complete_trade(me, item);

     if(owner->complete_trade(me, item)) {
       me->pay_money(price);
       return 1;
     } else {
         return 0;
     }
   } else
     return notify_fail("你的钱不够。\n");
}

int help(object me)
{
   write( @HELP
指令格式: buy <something> from <someone>

这一指令让你可以从某些人身上买到物品。
HELP
   );
   return 1;
}
