//mac's jiaolou1.c
// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","坤角楼");
  set("long",@LONG
这是岱庙围墙四隅的角楼，分别以四卦为名，以求避凶趋吉，楼中
有一面大碑，碑上书一大字：
[33m
				坤
[37m
LONG
  );
  set("exits",([
         "north":__DIR__"jiaolou3.c",
         "east" :__DIR__"zhengyan.c",
               ]));
   
        set("objects", ([
                __DIR__"npc/gang1" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
