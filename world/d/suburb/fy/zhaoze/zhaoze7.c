// 
// 


#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "火沼深处");
	set("long", @LONG
这里密布的荆棘挂满倒刺，挡在通往沼泽深处的方向。低矮的
小树丛挡住视线，使人辨不清方向。地下布满腐烂的枯叶，松松软
软的。偶尔有一两个气泡从地上的积水下涌出，带出令人作呕的刺
鼻气味。
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"zhaoze6",
]));

        set("item_desc", ([
                "bush": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n",
                "荆棘": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n",
		"woods" : "这里小树丛(woods)密布，但你似乎可以砍开(chop)它们。\n",
		"小树丛" : "这里小树丛(woods)密布，但你似乎可以砍开(chop)它们。\n"
        ]) );
        set("objects", ([
                __DIR__"npc/monster4" : 1,
       ]) );
	setup();
}

void init()
{	object ob;
	if( interactive( ob = this_player()))
	call_out("blowing", random(8) + 1, ob);
	add_action("do_chop","chop");
}

int blowing(object ob)

{
	int i;
	int damage;
        if(  ob && environment(ob) == this_object())
	{
	tell_object(this_object(), HIR "\n\n一个巨大的火球＂轰隆＂一声从地下爆出！！\n\n" NOR);
        damage = random(20)+20 - ob->query_temp("apply/armor_vs_fire");
        if(damage > 0 ) {
        ob->receive_wound("kee", damage);
        COMBAT_D->report_status(ob,1);
        }
	if( environment(ob) == this_object())
	call_out("blowing",random(8)+1, ob);	
	}
	else

	return 1;
}

void reset()
{
	::reset();
        remove_call_out("blowing");
        delete("exits/south");
        delete("exits/west");

}

int valid_leave(object me, string dir)
{
        remove_call_out("blowing");
	return 1;
}

int do_chop(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要砍开什么？\n");
                return 1;
        }
        if( arg == "bush" || arg == "荆棘" || arg == "woods" || arg == "小树丛")
        {
        me = this_player();
        obj = me->query_temp("weapon");
        if( !obj )
        {
        write("你空着手，怎么砍？\n");
        return 1;
        }
        if( obj->query("jungle"))
        {
	if( arg == "bush" || arg == "荆棘")
	{
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"zhaoze3");
        message_vision(sprintf("$N用手中的%s砍出一条向南的路．\n",obj->name()),
                me);
					}
        else
        message_vision(sprintf("$N用手中的%s砍向路边的荆棘．\n",obj->name()),
                me);

	}
	else
        {
        if( !query("exits/west") ) {
        set("exits/west", __DIR__"center");
        message_vision(sprintf("$N用手中的%s砍出一条向西的路．\n",obj->name()),
                me);
				        }
        else
        message_vision(sprintf("$N用手中的%s砍向路边的荆棘．\n",obj->name()),
                me);
	}
	me->start_busy(1);
	}
        else
        message_vision(sprintf("$N用手中的%s向丛生的荆棘一顿乱砍．\n",obj->name()),
                me);
        }
        else
         write("你要砍开什么？\n");
                return 1;
}

