// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/ge1.c

inherit ROOM;

void create ()
{
  set ("short", "守烟阁");
  set ("long", @LONG

只见得烟气馥馥仙风徐徐，阁中奇草百样色彩缤纷。正中设有
一圆翡翠珊瑚灵台，上有碧藕金丹。烟阁由八根缠凤柱高高擎
起，周围条条彩虹飞舞。

LONG);

  set("exits", ([
        "south"     : __DIR__"ge2",
        "southwest" : __DIR__"pan1f",
      ]));

  set("objects", ([
         __DIR__"npc/lishi1"  : 1,
     ]));

  setup();
}

