// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/pool
inherit ROOM;

void create ()
{
  set ("short", "池塘边");
  set ("long", @LONG

池塘四周紫竹环绕，而塘边的空地上还长着几丛洁白的牡丹。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhulin",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/d/qujing/wuzhuang/npc/ludongbin" : 1,
]));

  setup();
}
