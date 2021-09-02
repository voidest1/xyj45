inherit ROOM;

void create()
{
	set("short","空房间");
	set("long",@LONG
这里是 ES2 的「离岛」管训所, 如果你被送到这里, 表示:
你违反了游戏规则, 请好好的反省一下你的所作所为, 想离
开的话只要断线超过 15 分钟即可 :-) 
LONG
	);
	setup();
}

void init()
{
	if (!wizardp(this_player())) 
	add_action("block_cmd","",1);
}

int block_cmd()
{
	if((string)query_verb() == "look") return 0;
	if((string)query_verb() == "help") return 0;
	return 1;
}
