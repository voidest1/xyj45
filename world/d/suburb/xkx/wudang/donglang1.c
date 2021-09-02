// donglang1.c 东厢走廊
// by Xiang
// Modified by Marz 03/27/96

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厢走廊");
	set("long", @LONG
	你走在一条走廊上，东边有几间雅室，人来人往很热闹。西边是大殿。
LONG
	);

	set("exits", ([
		"east" : __DIR__"donglang2",
		"west" : __DIR__"sanqingdian",
	]));
	
	set("objects", ([
		CLASS_D("wudang") + "/xi" : 1]));
		
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "武当派") && dir == "east" &&
		objectp(present("zhang songxi", environment(me))))
	   return notify_fail("张松溪喝道：你不是武当弟子，不得入内。\n");
		
        return ::valid_leave(me, dir);
}
