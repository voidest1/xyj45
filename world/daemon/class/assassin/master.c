// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("金□", ({ "mastress assassin", "mastress", "assassin" }) );

	set("gender", "女性");
	set("age", 29);
	set("attitude", "peaceful");

	set("str", 26);
	set("int", 24);

	create_family("月牙神教", 25, "圣女");

	set("force", 1800);
	set("max_force", 1800);
	set("force_factor", 10);

	set("combat_exp", 1000000);
	set("score", 200000);
	set("env/wimpy", 50);
	
/*
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: consider :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
*/
	set_skill("unarmed", 80);
	set_skill("staff", 90);
	set_skill("blade", 70);
	set_skill("throwing", 60);
	set_skill("force", 100);
	set_skill("parry", 60);
	set_skill("dodge", 100);
	set_skill("perception", 80);
	set_skill("stealing", 40);

	set_skill("spicyclaw", 100);
	set_skill("serpentforce", 100);

	map_skill("unarmed", "spicyclaw");
	map_skill("force", "serpentforce");

	setup();
}

/*
void attempt_apprentice(object me)
{
	command("look " + me->query("id"));
	if( me->can_afford(100) ) {
		command("say 我们花紫会只收化子，" + RANK_D->query_respect(me)
			+ "您还是回去享福吧。\n");
		return;
	} else {
		command("nod");
		command("recruit " + me->query("id"));
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "beggar");
}


*/