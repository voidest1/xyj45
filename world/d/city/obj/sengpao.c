// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("黑布僧袍", ({  "seng pao", "pao", "cloth"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
     set("long", "一件普普通通的黑布僧袍。\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
