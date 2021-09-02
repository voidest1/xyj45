inherit NPC;
 
void give_jade();
void sell_drug();
 
void create()
{
        seteuid(getuid());
        set_name("沈万年",({"shen wen-nien","shen"}));
        set("title","沈记商行掌柜");
        set("gender", "男性" );
        set("age",45);
        set("combat_exp",30);
        set("attitude", "friendly" );
        set_temp("apply/dodge",5);
        set_temp("apply/attack",3);
        set("inquiry", ([
            "玉佩" : (: give_jade :),
            "蒙汗药" : (: sell_drug :),
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver",1);
}
 
void init()
{
        add_action("list_item","list");
        add_action("buy_item","buy");
}
 
int list_item()
{
        write("你看到:\n");
        write("柜子上一堆冥纸和香烛等, 标价 10 文钱. 墙上挂著几把竹扫帚,\n");
        write("每把 50 文钱. 柜台上摆\著一块木牌, 上面写著:\n");
        write("棺材: 时价. 没看到的东西问一下掌柜的, 我们应该都有.\n");
        return 1;
}
 
int buy_item()
{
        command("shake");
        command("say 我不卖东西给陌生人!");
        return 1;
}
 
void give_jade()
{
        object ob;
        if (this_player()->query_temp("give_alcohol")) {
               if(this_player()->query_temp("had_jade")) {
                    command("say 你真贪心耶... ");
                    return;
                }
                ob = new("/d/suburb/es/green/obj/jade");
		if (ob->violate_unique()) {
		command("hmm");
		command("say 这样东西... 刚刚有人来要过了.");
		command("shrug");
		destruct(ob);
		return;
		}
                ob->move(this_object());
                command("give jade to "
                   +(string)this_player()->query("id"));
                this_player()->set_temp("had_jade",1);
           }
           else command("?");
        return;
}
 
void sell_drug()
{
        if (this_player()->query_temp("know_drug")) {
            command("whisper "+(string)this_player()->query("id")+
            " 一份只要 10 两银子, 保证有效喔.\n");
            command("grin");
            this_player()->set_temp("can_buy_drug",1);
        }
        else command("?");
        return;
}
 
int accept_object(object who, object ob)
{
        object drug;
        if(who->query_temp("can_buy_drug") ) {
                if( ob->value() >= 1000 ) {
		drug = new("/obj/slumber_drug");
                drug->move(this_player());
                tell_room(environment(this_player()),
                "老板鬼鬼祟祟地塞了一样东西给"
                    +(string)this_player()->name()+"。\n",
                    ({this_object(), this_player()}) );
                tell_object(this_player(),"老板塞了一包蒙汗药给你。\n");
                }
                else {
                command("shake");
                command("say 想骗我啊?\n");
                this_player()->delete_temp("give_alcohol");
                this_player()->delete_temp("know_drug");
                }
        } else {
				if(!ob->value()) { 
					if(ob->name()=="单刀") {
						call_out("dest_stuff",3,ob);
						return 1;
					}
					else
					return 0;
				} else {
                command("say 我不知道你给我钱干嘛, 不过谢啦!");
                command("grin");
                }
        }
        return 1;
}
 
void dest_stuff(object ob) 
{
	destruct(ob);
	return;
}
