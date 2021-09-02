// npc: /d/city/npc/wei.c
// Jay 5/15/96

inherit NPC;

void create()
{
        set_name("韦春芳", ({ "wei chunfang", "chunfang", "wei" }) );
        set("gender", "女性" );
	set("title", "丽春院老板娘");
//	set("nickname", "鹿鼎公");
        set("age", 42);
        set("long", 
            "韦春芳是当朝鹿鼎公兼红花会总舵主韦小宝他娘，虽是徐"
	    "娘半老，但风韵尤存。\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 25000);

        set("max_kee", 300);
        set("max_gin", 100);
        set("force", 500);
        set("max_force", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "老娘我就是韦春芳。",
            "韦小宝" : "那是我的乖儿子，长得就像你。",
            "丽春院" : "我们丽春院可是扬州城里头一份的找乐子去处。",
            "here" : "我们丽春院可是扬州城里头一份的找乐子去处。",
       ]) );

        setup();
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                "韦春芳得意地说道：当年老娘我标致得很，每天有好几个客人。\n",
                "韦春芳怒骂道：辣块妈妈，要是罗刹鬼、红毛鬼子到丽春院来，老娘用大扫帚拍了出去