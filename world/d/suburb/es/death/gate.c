// Room: "/d/death/gate.c

inherit ROOM;

void create()
{
	set("short", "[1;37mé¬¼é¨å³[2;37;0m");
	set("long", @LONG
è¿éå°±æ¯èåçé´é´å¥å£ãé¬¼é¨å³ãï¼å¨ä½ é¢åçç«èä¸åº§é«å¤§ç
é»è²åæ¥¼ï¼è®¸å¤äº¡é­æ­£å­å­å¼å¼å°åéåè¿ï¼å ä¸ºä¸è¿é¬¼é¨å³å°±æ æ³å
åé³é´äºã
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bridge",
		"north" : __DIR__"gateway",
]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wgargoyle" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
