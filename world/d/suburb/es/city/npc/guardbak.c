// guard.c
#include <ansi.h>

string kill_passenger(object who);

inherit NPC;

void create()
{
        set_name("京师守城兵", ({ "City guard", "guard" }) );
        set("long",
          "这是个正在这里站岗的京师官兵，虽然和许多武林人物比起来，官兵\n"
          "们的武功实在稀松平常，但是他们是有组织、有纪律的战士，谁也不\n"
          "轻易地招惹他们。\n");

        set("attitude", "peaceful");
        set("vendetta_mark", "authority");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("attitude", "peaceful");
        set("vendetta_mark", "authority");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 100000);

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "守城官兵喝道：还不快放下武器束手就缚？\n",
                "守城官兵喝道：大胆刁民！竟敢在天子脚下造反？\n"
        }) );

        set("inquiry",  ([
                "出城":
                        "你可以在京城里找一找，说不定可以找到一些出城的令牌。\n",
               "out":
                       "你可以在京城里找一找，说不定可以找到一些出城的令牌。\n",
                ]) );

        set_skill("unarmed", 90);
        set_skill("sword", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("move", 100);

        set_temp("apply/attack", 90);
        set_temp("apply/defense", 90);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 90);
        set_temp("apply/move", 100);

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
}

void init()
{
//        add_action("do_out", "out");
	add_action("do_kill","kill");
//	add_action("go_out", "go");
}
/*
int do_out()
{
        object me;
        me = this_player();
             if( !me->query("marks/京师") )
             {
                command("say 没有官府通令，任何人不能出入京师。");
                write("出城方向的路被京师守城兵挡住了 。\n");
                return 1;
             }
             else
                return 0;
}

int go_out(string arg)
{
        object me;
        me = this_player();
        if( arg == "out" )
        {
             if( !me->query("marks/\101\156\105\106") )
             {
                command("say 没有官府通令，任何人不能出入京师。");
                write("出城方向的路被京师守城兵挡住了 。\n");
		return 1;
             }
             else
                return 0;
        }
        return 0;
}
*/
int do_kill(string arg)
{
        object me;
        me = this_player();
        if( arg == "guard" )
        {
	   kill_ob(me);
           return notify_fail( "守城兵大叫：反了！反了！" );
        }
        return 0;
}

int accept_object(object who, object ob)
{
//        if ( (string)ob->name() != "官府通令")
	if ( ob->query("id") != "token") 
        {
                command("say 这是什么东西啊！你想偷渡呀？");
                return 0;
        }

//        if ( !who->query("marks/京师") ) 
//	{
                say("京师守城兵连忙说道：原来是官府中人，您请出城。\n");
                who->set("marks/令牌",1);
//                return 1;
//	}
	
	ob->destruct();
        return 1;
}

