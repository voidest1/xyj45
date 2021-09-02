// Room: "/d/sanyen/tunnel.c

inherit ROOM;

void create()
{
	set("short", "隧道");
	set("long", @LONG
你走进了一个凿穿山壁开成的隧道，隧道也不甚长，约七、八丈左
右，西边就是隧道的出口，隧道中你可以闻到一股硫磺的味道，想必左
近便有温泉或是火山。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/suburb/es/sanyen/sroad2",
  "east" : "/d/suburb/es/sanyen/tunnele",
]));

	setup();
	replace_program(ROOM);
}
