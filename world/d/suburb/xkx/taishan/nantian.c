// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "南天门");
	set("long", @LONG
走完了十八盘，这里便是泰山顶的入口处。从这里附视山下，
群山如龟伏地，河流如蚓缠绕，天地空阔，无可名状。从这里往东
北走可到一个市集，往西走便是月观峰，往北走则是到玉皇顶之路。
LONG
	);

	set("exits", ([
//		"eastup" : __DIR__"tianjie",
		"northup" : __DIR__"yuhuang",
//		"west" : __DIR__"yueguan",
		"southdown" : __DIR__"shengxian",
	]));

	set("objects",([
		__DIR__"npc/jiang" : 1,
		__DIR__"npc/wei-shi3" : 2,
	]));

	set("outdoors", "taishan");
	setup();
}

int valid_leave(object me, string dir)
{
	object ob1, ob2, ob3;
	string mengzhu, shangshan, fae;
	
	if(!( ob1 = find_living("mengzhu")) )
	ob1 = load_object("/d/obj/clone/npc/meng-zhu");
	mengzhu = ob1->query("winner");

	if(!( ob2 = find_living("shangshan")) )
	ob2 = load_object("/d/obj/clone/npc/shang-shan");
	shangshan = ob2->query("winner");

	if(!( ob3 = find_living("fae")) )
	ob3 = load_object("/d/obj/clone/npc/fa-e");
	fae = ob3->query("winner");

	if( dir == "northup" ) { 
		if( present("jiang baisheng", environment(me)) 
		&& me->query("id") != mengzhu 
		&& me->query("id") != shangshan 
		&& me->query("id") != fae )
			return notify_fail("江百胜伸手拦住你说道：盟主很忙，现在不见外客，你下山去吧！\n");
		else if( me->query("id") == mengzhu ) {
			message_vision(HIY "\n江百胜诚惶诚恐的向$N跪倒磕头，大声喊道：盟主万岁，万岁，万万岁！\n" NOR, me);
		}	
		else if( me->query("id") == shangshan ) {
			message_vision(HIY "\n江百胜毕恭毕敬的向$N拜倒喊道：赏善使者您好！ 属下江百胜参见大人！\n" NOR, me);
		}	
		else if( me->query("id") == fae ) {
			message_vision(HIY "\n江百胜毕恭毕敬的向$N拜倒喊道：罚恶使者您好！ 属下江百胜参见大人！\n" NOR, me);
		}	
	}

	return ::valid_leave(me, dir);
}
