// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

这里的山路平缓但松散如泥，走在上面深一脚浅一脚，让人不
禁有点心虚。路边可以听见林中鸟儿的鸣唱，风不断地吹过，
四处开满无名野花。

LONG);

  set("exits", ([
        "east"   : __DIR__"shanlu3",
        "west"   : __DIR__"shanlu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}


