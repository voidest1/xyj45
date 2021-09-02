// wdroad7.c 黄土路
// by Xiang

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
	你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里是湖北境界，
据说经常有土匪出没，不可久留。
LONG
	);
        set("outdoors", "wudang");

	set("no_sleep_room",1);

	set("exits", ([
		"east" : __DIR__"wdroad6",
		"west" : __DIR__"wdroad8",
		"southup" : __DIR__"tufeiwo1",
	]));

	setup();
	replace_program(ROOM);
}

