// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;

void create()
{
        set_name("大洗衣盆", ({"pen"}));
   set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
        set("long", "一个大洗衣盆，里面都是脏衣服．\n"),
   set("no_get", 1);
   }
   setup();
}
int is_container()
{
set("objects", (["/u/bula/gao/obj/kaoji"]) );
}
