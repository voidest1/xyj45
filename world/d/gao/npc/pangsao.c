// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// laoyu.c

inherit F_VENDOR_SALE;
void create()
{
    reload("pang_sao");
       set_name("胖嫂", ({"pang sao", "pang", "sao"}));
       set("long",
"胖嫂原是裁缝，后在长安的儿子发了财，便自家开了布店．\n");
       set("gender", "女性");
   set("title", "老板娘");
   set("combat_exp", 1100);
       set("age", 46);
   set("per", 12);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 15);
       set("vendor_goods", ([
                "hat": "/d/gao/obj/hat",
                "shoes": "/d/gao/obj/shoes",
     "magua": "/d/gao/obj/magua",
                "pipao": "/d/gao/obj/piyi",
       ]) );
   setup();
       add_money("silver", 1+random(3));
        carry_object("/d/gao/obj/ao")->wear();

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
        switch( random(1) ) {
                case 0:
                        say(name()+ "笑眯眯的迎上来：这位" +
RANK_D->query_respect(ob)
                                + "，随便看看．\n");
                        break;
        }
}

