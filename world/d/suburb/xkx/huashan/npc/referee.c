// referee.c

inherit NPC;
#include <ansi.h>;

int do_bihua(string);
string ask_me();
int do_halt();

void create()
{
	set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
	set("combat_exp",60000);
        set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_kee", 800);
	set("max_gin", 800);
	set("max_force", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	set("inquiry", ([
		"比武大会"       : (: ask_me :),
	]));

	setup();

        carry_object("/d/obj/clone/misc/cloth")->wear();
        carry_object("/d/suburb/xkx/city/obj/changjian")->wield();
}


void init()
{
        ::init();	
        add_action("do_bihua", "bihua");
        add_action("do_bihua", "bi");
        add_action("do_bihua", "fight");
        add_action("do_halt", "halt");
        add_action("do_halt", "h");
}

string ask_me()
{
	object* ob;
	int i;
	ob = users();

	if ( !wizardp(this_player()) ) return "你无权召开比武大会！\n";

	for ( i=sizeof(ob); i>0; i-- ) {
		ob[i-1]->move("/d/suburb/xkx/huashan/sheshen");
	}

	return "好，现在比武大会正式开始，全体集合！\n";
}

int do_bihua(string arg)
{     
	object ob1, ob2;
        object old_target;

	ob1 = this_player();
        
	if( !arg || arg=="" ) return 0;  

	if ( arg == "gongping zi" || arg == "zi" || arg == "referee" )
           {
             command("say " + "你不能跟我比划！\n");
             return 1;
            }

	if ( this_object()->query_temp("busy") ) 
		return notify_fail("每次只能有两人参加比武。\n");

        if (!ob2 = present(arg,environment(ob1)) ) 
		return notify_fail("你想跟谁比划？\n");
        if (ob1 == ob2)    return notify_fail("你不能攻击自己。\n");


	if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
		message_vision("\n$N对着$n说道