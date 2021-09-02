// Room: "/d/snow/mstreet1.c

inherit ROOM;

void create()
{
	set("short", "雪亭镇街道");
	set("long", @LONG
你现在正走在雪亭镇的街道上，东边不远处有一间高大的院子，门
口立著一根粗大的旗杆，旗子上写著「淳风武馆」，往南只听得人声鼎
沸，是个五十尺见方的广场，人来人往相当热闹。往北可望见一座牌坊
，年代久远，上面的字迹早已看不出是什么字，出了牌坊就是镇外。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/suburb/es/snow/bank",
  "south" : "/d/suburb/es/snow/square",
  "north" : "/d/suburb/es/snow/mstreet2",
  "east" : "/d/suburb/es/snow/school1",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
