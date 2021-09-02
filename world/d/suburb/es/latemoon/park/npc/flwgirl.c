// flowergirl.c

inherit NPC;

void create()
{
	set_name("采花少女", ({ "girl" }) );
	set("gender", "女性" );
	set("age", 15);
	set("per", 30-random(15) );
        	set("long", 
		"采花少女是绮云镇居民的小孩，从小就到晚月庄来摘桂花，蓝止\n"
		"萍很喜欢她们，也教给她们了些基本的武功，时间久了，这些少\n"
		"女的功夫还都不错。\n"
	);
	set("combat_exp", 20000);
	set("attitude", "friendly");
         	set("chat_chance", 4);
       	set("chat_msg", ({
"顽皮的采花少女向你扮个鬼脸。  *^G^* \n",
"采花少女说道：华中理工大学的桂花树比晚月庄多多了，你知道吗？\n",
"采花少女望着天边的晚霞，双手托着香腮，说道：我好想去华工大摘桂花。\n",
"采花少女嘀咕着：听说华工的桂花有好几种呢。\n",
       }) );

        	set("chat_chance_combat", 10);
        	set("chat_msg_combat", ({
"采花少女秀眉微蹙，说道：你欺负我年纪小是吗？\n",
"采花少女说道：你要是再无理取闹，让火玫瑰毒死你！\n",
"采花少女骂道：你这无赖，别死缠着我！\n",
        	}) );
	set("inquiry", ([
		"桂花" : "华中理工大学的桂花树比晚月庄多多了，你知道吗？",
	]) );

	set_skill("parry", 30);
	set_skill("dodge", 70);
	set_skill("unarmed", 120);
	set_skill("throwing", 150);
       	set_skill("stormdance", 45);

        map_skill("dodge", "stormdance");
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 0);

	setup();
        	carry_object("/d/suburb/es/latemoon/obj/skirt3")->wear();
        	for(int i=1; i<=2; i++){
	carry_object("/d/suburb/es/latemoon/park/npc/obj/guihua")->wield();
        	}
}


