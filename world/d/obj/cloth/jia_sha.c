// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIY"袈裟"NOR, ({ "jia sha", "sha" }) );
  set("long", "一件光彩照人的袈裟。\n");
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 15);
    set("armor_prop/spells", 10);
    set("armor_prop/dodge", 10);
  }
  setup();
}

