// Room: "/d/green/path1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一条看来相当荒凉的小路, 两旁杂草丛生, 好像很久都没有人来过
的样子. 往南很远的地方可以看到村子的入口, 往北的路似乎不是很明
显.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/suburb/es/green/path0",
  "south" : "/d/suburb/es/green/path2",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
