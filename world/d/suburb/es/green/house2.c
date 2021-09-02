// Room: "/d/green/house2.c

inherit ROOM;

void create()
{
	set("short", "民宅");
	set("long", @LONG
这是一间简陋的民宅, 屋顶隐约还可以看到一些破洞. 墙角堆
著些柴火, 墙壁上还可以看到烟熏的痕迹. 除了一些简陋的家具外
屋内空空荡荡的.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/suburb/es/green/field0",
]));
	set("no_clean_up", 0);
	set("objects", ([
		"/d/suburb/es/green/npc/oldman" :1,
		"/d/suburb/es/green/npc/oldwoman" : 1,
		]) );

	setup();
	replace_program(ROOM);
}
