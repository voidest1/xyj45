// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// shoe.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;


void create()
{
   set_name(YEL "绣花小鞋" NOR, ({ "shoes" }) );
   set_weight(900);
   if( clonep() )
     set_default_object(__FILE__);
   else {
                set("LONG", "一双小巧精致的绣花鞋。  \n");
     set("material", "cloth");
     set("unit", "双");
//     set("value", 300);
     set("armor_prop/armor", 1 );
     set("female_only", 1);
   }
   setup();
}
//int query_autoload() { return 1; }

