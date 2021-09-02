//mac's jiaolou3.c
// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","坎角楼");
  set("long",@LONG
这是岱庙围墙四隅的角楼，分别以四卦为名，以求避凶趋吉，楼中
有一面大碑，碑上书一大字：
[31m
				坎
[37m
LONG
  );
  set("exits",([
         "south":__DIR__"jiaolou1.c",
         "east" :__DIR__"houzai.c",
               ]));
        set("objects", ([
                __DIR__"npc/gang3" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
