//xuantie.c
inherit ITEM;
void create()
{
        set_name( "千年神木", ({ "shen mu","mu"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是一块千年神木，表面黑中透红的，看上去十分坚硬。\n"
		    "似乎是制造兵器的绝好材料。\n");
                set("value", 0);
                set("material", "wood");
              }
}
