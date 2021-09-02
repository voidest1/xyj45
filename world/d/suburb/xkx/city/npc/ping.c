// ping.c 平一指

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他就是医术高超的「杀人神医」平一指。可是他性格古怪，不是什么人都医的。\n");
	set("age", 65);

	set("int", 30);
	
	set("kee", 1000);
	set("max_kee", 1000);
	set("gin", 1000);
	set("max_gin", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);

	set("vendor_goods", ({
	}));

	setup();
	add_money("gold", 1);
}

void init()
{
//add_action("do_buy", "buy");
}
