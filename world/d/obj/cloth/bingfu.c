// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("兵服", ({"cloth", "bingfu"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
     set("long", "一件兵服，前后有铜镜护心，中绣大唐二字．\n");
                set("material", "cloth");
                set("value", 300);
                set("unit", "件");
                set("armor_prop/armor", 10);
        }
        setup();
}

