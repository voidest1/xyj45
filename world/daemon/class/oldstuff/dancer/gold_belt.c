// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// gold_belt.c

#include <ansi.h>

inherit EQUIP;

void create()
{
   set_name( HIY "软金束带" NOR, ({ "gold belt", "belt" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "条");
     set("value", 27000);
     set("material", "cloth");
     set("armor_type", "waist");
     set("armor_prop/armor", 4);
     set("armor_prop/dodge", -1);
   }
}
