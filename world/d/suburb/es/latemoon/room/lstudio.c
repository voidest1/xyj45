#include <room.h>
inherit ROOM;

void create()
{
    set("short", "内书房");
	set("long", @LONG
这是一间安静的书房, 光线适中, 近窗边有一张桌子, 旁有书橱
还有一个古琴放在平台上! 墙上除了美丽的饰物外, 还挂了一些书画                  
有一股浓郁清新的书香气息!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" :__DIR__"lcenter",

]));

    set("objects", ([
        __DIR__"npc/old" : 1,
        __DIR__"npc/killer" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
