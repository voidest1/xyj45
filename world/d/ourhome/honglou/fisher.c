// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/hkgroup/fisher
inherit ROOM;

void create ()
{
  set ("short", "钓鱼台");
  set ("long", @LONG

　　台面上放着一碟清蒸鱼。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"village",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
