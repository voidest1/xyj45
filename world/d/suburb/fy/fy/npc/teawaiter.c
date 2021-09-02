// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("茶博士", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "茶博士正忙着招呼客人, 一手提着茶壶, 一手拿着抹布\n");
	set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "茶博士");
        set("vendor_goods", ([
                "/obj/example/teapot": 10,
                "/obj/example/dumpling": 10,
                "/obj/example/chicken_leg": 20,
        ]) );
        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "茶博士笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "茶博士用毛巾抹了抹靠门的一张桌子，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "茶博士说道：这位" + RANK_D->query_respect(ob)
                                + "，进来尝尝才采的新茶叶。哇! 好香啊!...\n");
                        break;
        }
}

