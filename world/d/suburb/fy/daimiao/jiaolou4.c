// 
// 

//mac's jiaolou4.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","哏角楼");
  set("long",@LONG
这是岱庙围墙四隅的角楼，分别以四卦为名，以求避凶趋吉，楼中
有一面大碑，碑上书一大字：
[33m
				哏
[37m
LONG
  );
  set("exits",([
         "south":__DIR__"jiaolou2.c",
         "west" :__DIR__"houzai.c",
               ]));
          set("objects", ([
                __DIR__"npc/gang4" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
