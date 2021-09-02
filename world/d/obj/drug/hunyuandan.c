// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hunyuandan.c 混元丹 

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("混元丹", ({"hunyuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "一颗略带香气的药丸．\n");
                set("value", 2000);
          set("drug_type", "良药");
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么药？\n");
        if ((int)this_player()->query("eff_sen") == 
            (int)this_player()->query("max_sen"))
                return notify_fail("你现在不需要用混元丹。\n");
        else {
                this_player()->receive_curing("sen", 40);
                message_vision("$N吃下一颗混元丹，脸色看起来好多了．\n",
this_player());
                destruct(this_object());
                return 1;
        }
}

