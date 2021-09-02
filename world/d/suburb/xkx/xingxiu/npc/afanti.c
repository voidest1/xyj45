// npc: /d/xingxiu/npc/afanti.c
// Jay 3/26/96

inherit NPC;

//string ask_me();

void create()
{
        set_name("阿凡提", ({ "afanti" }) );
        set("gender", "男性" );
        set("age", 48);
        set("long", 
            "他头上包着头巾，长着向上翘的八字胡，最喜欢捉弄巴依、帮助穷人。他常"
            "给别人出谜语。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set_skill("unarmed", 30);
        set_skill("dodge", 25);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2500);

        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "我就是纳苏尔的阿凡提。",
            "here" : "这里可真是个好地方。",
            "纳苏尔" : "是我出生的地方。",
            "谜语" : "你帮我找到小毛驴，我就给你出谜语。",
            "巴依" : "他把我关在这里，有吃有喝，我就不走了。巴依是个坏蛋，愿胡大惩罚他。",
            "毛驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
            "驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
            "小毛驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
            "卷帘格" : "卷帘格指谜底各字顺序颠倒过来和谜面相扣。",
            "胡大" : "就是真主。又名安拉或阿拉。",
            "真主" : "真主至大，万物非主，唯有真主。穆罕默德是真主的使者。",
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
             "阿凡提叹了口气：嗨，可惜我的驴。\n",
        }) );
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/dongbula");
}

void init()
{
        ::init();
        add_action("do_answer","answer");
}

int accept_object(object who, object ob)
{
     if((string)ob->query("name")=="小毛驴") {
           remove_call_out("destroying");
           call_out("destroying", 1, this_object(), ob);

           if( who->query_temp("marks/谜") ) {
                 write("阿凡提笑了笑，说：你先把上个谜猜出来再说。\n");
//               destruct(ob);
                 return 1;
           }
           else {
                 write("阿凡提笑得嘴都合不上了，说：多谢这位" + 
                       RANK_D->query_respect(who) +
                       "的帮助，咱们猜个谜语吧：\n");
                 switch(random(20)) {
                   case 0:
                       write("妇女读物。(打一本泥潭玩家名)\n");
                       who->set_temp("marks/谜", 1);
                       break;
                   case 1:
                       write("雪在烧，雪在烧。(打一本泥潭玩家名)\n");
                       who->set_temp("marks/谜", 2);
                       break;
                   case 2:
                       write("邓小平之后。(打一本泥潭NPC名)\n");
                       who->set_temp("marks/谜", 3);
                       break;
                   case 3:
                       write("御用经典。(打一本泥潭玩家名)\n");
                       who->set_temp("marks/谜", 4);
                       break;
                   case 4:
                       write("打谷场上的NPC。(打一本泥潭玩家名)\n");
                       who->set_temp("marks/谜", 5);
                       break;
                   case 5:
		       write("巴黎习语。(打一本泥潭技能名，卷帘格)\n");
                       who->set_temp("marks/谜", 6);
                       break;
                   case 6:
                       write("拱猪入门。(打一字)\n");
                    // this riddle made by 老哈（美国　明尼苏达大学）
                       who->set_temp("marks/谜", 7);
                       break;
                   case 7:
                       write("拱猪王闷闷不乐。(打一字)\n");
                    // this riddle modified from one made by 绿田　（美国　密执安州）
                       who->set_temp("marks/谜", 8);
                       break;
                   case 8:
                       write("锦帆才渡儿郎去。(打一本泥潭巫师网名)\n");
                    // this riddle made by 岳涵　（美国　密执安州）
                       who->set_temp("marks/谜", 9);
                       break;
                   case 9:
                       write("德意日战败。(打一本泥潭NPC名)\n");
                    // this riddle modified from one made by 牛　（美国）
                       who->set_temp("marks/谜", 10);
                       break;
                   case 10:
                       write("整年当兵。(打一本泥潭NPC名)\n");
                    // this riddle made by 四月　（美国）
                       who->set_temp("marks/谜", 11);
                       break;
                   case 11:
                       write("欧阳锋练功。(打一成语)\n");
                    // this riddle made by 魔　（美国）
                       who->set_temp("marks/谜", 12);
                       break;
                   case 12:
                       write("胡踢乱踹。(打一本泥潭NPC名)\n");
                    // this riddle made by 居士　（美国）
                       who->set_temp("marks/谜", 13);
                       break;
                   case 13:
                       write("麦克杰克逊。(打二本泥潭NPC名)----回答时二名一起回答，中间不加任何标点。\n");
                       who->set_temp("marks/谜", 14);
                       break;
                   case 14:
                       write("召。