// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("抱琴",({"bao qin","fairy", "girl"}));
       set("long",
"其仿佛兮若轻云之蔽月，飘摇兮若流风之回雪。远而望之，皎若
太阳升朝霞。迫而察之，灼若芙渠出绿波。\n");
       set("title", "月宫伺女");
       set("gender", "女性");
       set("age", 18);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
   set("int", 30);
       set("max_kee", 800);
       set("max_gin", 600);
       set("max_sen", 600);
       set("force", 600);
       set("max_force", 600);
       set("force_factor", 40);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 40);
       set("combat_exp", 100000);
       set_skill("literate", 80);
       set_skill("unarmed", 80);
       set_skill("dodge", 100);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 80);

create_family("月宫", 3, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
}


