// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// ironarmor.c
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("亮银甲", ({"silver armor", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
           set("long", "一件银光灿灿的盔甲．\n");
                set("value", 8000);
                set("material", "iron");
                set("armor_prop/armor", 45);
     set("armor_prop/dodge", -10);
             }
        setup();
}

