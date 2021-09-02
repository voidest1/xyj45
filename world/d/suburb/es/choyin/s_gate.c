// Room: "/d/choyin/s_gate.c

inherit ROOM;

void create()
{
	set("short", "乔阴县城南门");
	set("long", @LONG
这里是乔阴县城的南门，由于这个南门是十多年前重建的，因此和
古老斑驳的东、西、北门相比，南门显得漂亮许多，而且南门正对著县
府衙门，平日的修缮当然也勤快些。乔阴县城南门外住著许多上次羿水
河鲁公堤溃决之后迁来的农民，因此虽然出了城门，街道依然人来人往
，往东是一条沿著城墙的街道，可以经过火龙将军庙入城，西边的街道
沿著城墙通往新建的驿站，往南则是许多房舍与农田。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"crossroad",
		"east" : __DIR__"dragon_temple",
	        "south" :__DIR__"spath",  
           ]));
	set("objects", ([
		__DIR__"npc/cityguard": 2
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
