inherit ROOM;

void create()
{
        set("short", "小径");
        set("long", @LONG
这条蜿蜒的小径通往东南方, 在你的东面是一处陡坡, 而在你的
西边是一座茂密的竹林。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
           "northwest" :__DIR__"sroad3",
           "west" :__DIR__"bamboo1",
           "south" :__DIR__"sroad4",

]));

        set("objects", ([
           "/d/suburb/es/latemoon/npc/butterfly" : 1 ]) );
        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
