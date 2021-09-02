// Npc: /daemon/class/shaolin/xuan-ku.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("玄苦大师", ({
		"xuanku dashi",
		"xuanku",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材瘦高，\n"
		"脸上满布皱纹，手臂处青筋绽露，似乎久经风霜。\n"
	);


	set("nickname", "罗汉堂首座");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_kee", 1500);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 2000);
	set("jiali", 150);
	set("combat_exp", 200000);
	set("score", 500000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 120);
	set_skill("shaolin-shenfa", 120);
	set_skill("parry", 120);
	set_skill("cuff", 120);
	set_skill("staff", 120);
	set_skill("blade", 120);
	set_skill("sword", 120);
	set_skill("luohan-quan", 120);
	set_skill("weituo-gun", 120);
	set_skill("xiuluo-dao", 120);
	set_skill("fumo-jian", 120);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "luohan-quan");
	map_skill("cuff", "luohan-quan");
	map_skill("staff", "weituo-gun");
	map_skill("blade", "xiuluo-dao");
	map_skill("sword", "fumo-jian");

	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 36, "弟子");

	set("inquiry", ([
		"十八罗汉阵"       : (: ask_me :),
		"罗汉大阵"	   : (: ask_me :)
	]));

	setup();

        carry_object("/d/suburb/xkx/shaolin/obj/jiedao")->wield();
        carry_object("/d/suburb/xkx/shaolin/obj/xuan-cloth")->wear();
}

#include "/daemon/class/shaolin/xuan-ku.h"




