
#include <ansi.h>

inherit NPC;
void pay_him(object who, int amount);
void create()
{
	int i,amun;
	set_name( "黄麻子", ({ "huang", "huang ma zi" }) );
	set("long", "这是银钩赌坊的职业赌手，骰子上的功夫出神入化。\n");
	set("attitude", "friendly");
	set("title", HIW "银钩手" NOR);
        set("force_factor", 30);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 99999);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
	set("age", 33);
        set("gender", "男性" );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);
	set("per",5);
	set("lower_limit",1);
	set("too_late",0);
	set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0);
	set("max_force",400000);
	set("force_factor",250);
	set_skill("throwing",200);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set("combat_exp", 50000000);
	setup();
        carry_object(__DIR__"obj/yingoupao")->wear();
	carry_object(__DIR__"obj/guzi")->wield();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_bet", "bet");
	
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "黄麻子笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，过来赌两手，开开心吧。\n");
                        break;
                case 1:
                        say( "黄麻子晃了晃手中的骰子，叫道：这位" + RANK_D->query_respect(ob)
                                + "，小赌可以养家糊口，大赌可以定国安邦。来吧！\n");
                        break;
                case 2:
                        say( "黄麻子说道：这位" + RANK_D->query_respect(ob)
                                + "，进来！进来！ 输了算我的！\n");
                        break;
        }



	return;

}
 
string *dice = ({
"[31m
	⊙ 

[37m",
"	⊙

	    ⊙
",
"	⊙
	  ⊙ 
	    ⊙
",
"	[31m⊙  ⊙

	⊙  ⊙
[37m",
"	⊙  ⊙
	  ⊙
	⊙  ⊙
",
"	⊙ ⊙
	⊙ ⊙
	⊙ ⊙
"
		});
int do_bet(string arg)
{
        int i,bet_amt;
        int bet_type;
        object me, gold;
        string message;
	if(!arg || !sscanf(arg, "%d %d",bet_type,bet_amt))
                return notify_fail("bet <种类> <金量>\n");
	if(bet_type>18 || bet_type < 0)
		return notify_fail("种类只可从零到十八\n");
	me = this_player();
	gold = present("gold_money", me);
	if(!gold) return notify_fail("你身上没有金子。\n");
	if((int) gold->query_amount() < bet_amt)
	return notify_fail("你身上没有那麽多金子。\n");	
	if((int) this_object()->query("lower_limit") > bet_amt)
	return notify_fail("这张台的最小赌注是"+chinese_number((int) this_object()->query("lower_limit"))+"两金子。\n");
        if((int) this_object()->query("too_late") )
        return notify_fail("这铺来不及了，等下手吧．\n");
	if((int) me->query("gamble/amount"))
	{ 
	if(bet_type != (int) me->query("gamble/type"))
	return notify_fail("你不可在一铺中下不同的注．\n");
        gold->add_amount(-bet_amt);
        me->start_busy(1);
        if(bet_type == 0)
                message = sprintf(RED"小"NOR);
        if(bet_type == 1)
                message = sprintf(RED"大"NOR);
        if(bet_type == 2)
                message = sprintf(RED"围骰"NOR);
        if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));
       message_vision(sprintf("$N又从身上拿出%s两黄金，加压在%s上．\n",
                                chinese_number(bet_amt), message), me);
        bet_amt += (int) me->query("gamble/amount");
                me->set("gamble/amount",bet_amt);

	}
	else
	{
	gold->add_amount(-bet_amt);
	me->start_busy(1);
	if(bet_type == 0)	
		message = sprintf(RED"小"NOR);
	if(bet_type == 1)
		message = sprintf(RED"大"NOR);
        if(bet_type == 2)
                message = sprintf(RED"围骰"NOR);
	if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));
	message_vision(sprintf("$N从身上拿出%s两黄金，压在%s上．\n",
				chinese_number(bet_amt), message), me);
	me->set("gamble/type",bet_type);
	me->set("gamble/amount",bet_amt);
	}
	if( find_call_out("rolldice") == -1)
		call_out("rolldice",30);
	if( find_call_out("rolldice") >10 && find_call_out("advertise") == -1)
		call_out("advertise",random(5)+1);
return 1;
}
void advertise()
{
        switch( random(3) ) {
                case 0:
message_vision("$N向你笑道：快下注！这注你一定会赢！\n",this_object());
                        break;
                case 1:
message_vision("$N说道：再不下注就来不及了！\n",this_object());
                        break;
                case 2:
message_vision("$N满面红光，耸恿着大家：加！再加大你的赌注！一定赢！\n",this_object());

                        break;
        }

        if( find_call_out("rolldice") >=10)
                call_out("advertise",random(4)+5);
return;
}

void rolldice()
{
	this_object()->set("too_late",1);
	message_vision("$N大声叫道：下定注！说罢，将手中的三粒骰子撒向碗里．\n",this_object());
	message_vision("\n．．．三粒骰子在碗里蹦跳着，发出悦耳的声音．．．\n",this_object());
	call_out("first_dice",1);
return;
}

void first_dice()
{
	int first;
        switch( random(3) ) {
                case 0:
        message_vision("\n一粒骰子弹了几下，停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n一粒骰子＂叮叮叮＂的跳动了几下，缓缓的停了下来：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n三粒骰子相互一撞，一颗直落碗底：\n\n",this_object());

                        break;
        }

	first = random(6);
	message_vision(dice[first], this_object());
	this_object()->set("first_dice",first+1);
	call_out("second_dice",1);
return;
}

void second_dice()
{
	int second;
        switch( random(3) ) {
                case 0:
       message_vision("\n又一粒骰子缓缓的停了下来：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n第二粒骰子在碗边旋转不停．．忽地翻了个身：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n二粒骰子相互一撞，其中一颗跳了一跳：\n\n",this_object());

                        break;
        }
        second= random(6);
        message_vision(dice[second], this_object());
        this_object()->set("second_dice",second+1);
	call_out("third_dice",1);


return;
}
void third_dice()
{
        int third;
        switch( random(3) ) {
                case 0:
       message_vision("\n最后一粒骰子在碗里滑了两下，终于停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n还有最后一粒骰子嘀遛遛的转个不停．．终于：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n最后一粒骰子也终于停稳了：\n\n",this_object());

                        break;
        }
        third= random(6);
        message_vision(dice[third], this_object());
        this_object()->set("third_dice",third+1);
        call_out("end_the_round",1);


return;
}

void end_the_round()
{
	int tot,reward,i,first, second, third;
	object *inv;
	first = (int) this_object()->query("first_dice");
        second= (int) this_object()->query("second_dice");
        third = (int) this_object()->query("third_dice");

// announce results:
message_vision(sprintf("\n$N高声叫道：%s，%s，%s，",
		chinese_number(first),chinese_number(second),chinese_number(third)),
		this_object());
// see who is the winner!
if( second == first && third == first)
{
message_vision("大小通吃！！\n",this_object());
inv = all_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
	if( userp(inv[i]) && (int) inv[i]->query("gamble/amount") )
	{
		if((int) inv[i]->query("gamble/type") == 2)
		{
		message_vision("赢家－$N，一赔三十六！！\n",inv[i]);
		reward = (int) inv[i]->query("gamble/amount") * 37 * 10000;
// also increae his betting skill
		inv[i]->improve_skill("betting", reward/10000);
		pay_him( inv[i],reward);
		}
		inv[i]->set("gamble/amount",0);
	}
        }


}
else
{
tot = first+second+third;
message_vision(sprintf("%s点，",chinese_number(tot)),this_object());
if( tot>10 )
message_vision("赔大吃小！\n",this_object());
else
message_vision("赔小吃大！\n",this_object());


inv = all_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
        if( userp(inv[i]) && (int) inv[i]->query("gamble/amount") )
        {
		if((int) inv[i]->query("gamble/type") == tot)
		{
                message_vision("赢家－$N，一赔八！\n",inv[i]);
                reward = (int) inv[i]->query("gamble/amount") * 9 * 10000;
// also increae his betting skill
                inv[i]->improve_skill("betting", reward/10000);
                pay_him( inv[i],reward);
		}
		else {
                if(((int) inv[i]->query("gamble/type") == 0 && tot <=10 ) ||
			((int) inv[i]->query("gamble/type") == 1 && tot > 10 ))
                {
                message_vision("赢家－$N，一赔一！\n",inv[i]);
                reward = (int) inv[i]->query("gamble/amount") * 2 * 10000;
// also increae his betting skill
                inv[i]->improve_skill("betting", reward/10000);
                pay_him( inv[i],reward);
                }
		}
                inv[i]->set("gamble/amount",0);
        }
        }


}
this_object()->set("too_late",0);
this_object()->set("first_dice",0);
this_object()->set("second_dice",0);
this_object()->set("third_dice",0);

return;
}
void pay_him(object who, int amount)

{
        object ob;
        object cash, tencash, gold, silver, coin;

        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}
int accept_object(object who, object ob)
{
	int bet_type;
	string message;
	
                if( ob->value() >= 10000) {
                        say("黄麻子呵呵的笑道：谢赏...\n");
	message_vision("$N在$n耳边嘀咕了几句．．\n",this_object(),who);
	bet_type = random(19);
        if(bet_type == 0)
                message = sprintf(RED"小"NOR);
        if(bet_type == 1)
                message = sprintf(RED"大"NOR);
        if(bet_type == 2)
                message = sprintf(RED"围骰"NOR);
        if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));

	tell_object(who,"黄麻子悄悄告诉你：下手儿压"+message+"，一定赢！\n");
	message_vision("$N会心的微笑起来．．\n",who);
	
                        return 1;
                } else {
                    say("黄麻子说道：这点钱你还是自己用吧！\n");
                        return 0;
                }
        return 0;
}

