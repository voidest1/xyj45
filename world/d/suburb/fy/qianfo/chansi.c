//mac's chansi.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","兴国禅寺");
  set("long",@LONG
青石砌起的山门上刻着：兴国禅寺。寺内飘来的阵阵佛香给人一
种肃穆的感觉。山门两旁的对联格外引人注目：
[35m
		暮	经
		鼓	声
		晨	佛
		钟	号
		惊	唤
		醒	回
		世	苦
		间	海
		名	梦
		利	迷
		客，	人。	
[37m
LONG
  );
        set("objects", ([
                __DIR__"npc/bonze2" : 2,
       ]) );
  set("exits",([
         "southdown":__DIR__"fudi.c",
         "north"    :__DIR__"jinggang.c"
               ]));
   
          set("outdoors", "qianfo");
	setup();
  replace_program(ROOM);
}
