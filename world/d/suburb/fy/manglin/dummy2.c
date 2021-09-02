inherit ROOM;
// 
// 


void create()
{
        set("short", "莽林之中");
        set("long", @LONG
四周古树参天，荆棘密布。浓密宽厚的树叶遮蔽了日月星辰，使人分不出
昼夜。四下如死一般的寂静，只有风吹过树梢的沙沙之声。偶尔一两声虎啸狼
嚎随着腥风飘至耳际。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"groupn2",
  "south" : __DIR__"groups2",
  "east" : __DIR__"groupe2",
  "west" : __DIR__"groupw2",
]));
        setup();
        replace_program(ROOM);
}