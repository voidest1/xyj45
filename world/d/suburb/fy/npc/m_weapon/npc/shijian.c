// npc: shijian.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("侍剑", ({ "shijian"}) );
	set("nickname", RED "剑" NOR );
	set("gender", "男性" );
	set("age", 20);
	set("long", 	
		"他头上包着白布头巾，一袭白袍，没有一丝褶皱。\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",500);
	set("jiali",50);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);

	set("combat_exp", 250000);
	set("score",0);
	
	set("attitude", "peaceful");
        
	set("inquiry", ([
		"铸剑"  : "师傅命我帮助别人铸剑，但到现在也不见一个人影。谁要铸剑呢？\n",
		"原料"  : "铸剑可用寒丝羽竹，海底金母，千年神木。但效果各不一样。\n",
	]) );

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_zhu","zhu");
}


int accept_object(object who, object ob)
{	
	if(!(who->query_temp("sword") ) ){
		message_vision(HIC"师傅没有同意为你铸剑，您请回吧！\n"NOR, who);
		return 1;
	}
	who->delete_temp("sword");
	who->set_temp("m_sword",1);
	switch ((string)ob->query("name") ) 
	{
		case "千年神木": 
			who->add_temp("shenmu",1);
			break;
		case "海底金母":
			who->add_temp("jinmu",1);
			break;
		case "寒丝羽竹": 
			who->add_temp("hanzhu",1);
			break;
		default :
			message("vision","这是什么！师傅说这不能用来打造兵器！",who);
			return 0;
	}
	message("vision","侍剑低头检视了一下手中的"+(string)ob->query("name")+
			"点了点头说：\n", who);
	message("vision","。。。好我们现在就开始铸剑\n", who);
	write("请这位"+RANK_D->query_respect(who)+"给剑起名字吧！(zhu 剑的名字 英文代号)\n");
	return 2;
}

int do_zhu(string arg)
{
	string o_name,id,w_name;
	object sword,make_time;   //生成的武器句柄
	object me;
	me = this_player();
	if(!(me->query_temp("m_sword")) ) 
		return notify_fail("什么?\n");
	me->delete_temp("m_sword");
	me->delete_temp("get_orc");
	me->delete_temp("or");

	if((me->query("weapon/make")) ){
		say("侍剑一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？\n");
		return 1;
	}
	if( !arg )
		return notify_fail("侍剑认真的说：想好剑的名称及代号后在对我说。\n");

	sscanf(arg ,"%s %s" ,w_name ,id);
	if(!w_name||!id)
		return notify_fail("什么?(使用zhu 剑的名字 英文代号\n)");
	if(me->query_temp("shenmu") ) o_name="千年神木";
	if(me->query_temp("jinmu") )   o_name="海底金母";
	if(me->query_temp("hanzhu") )   o_name="寒丝羽竹";
	make_time=NATURE_D->game_time();
	message_vision(me->name()+"沉吟了一会，对侍剑巧声说了几句话。侍剑点了点头。说：好吧！\n",me );
	message_vision("\n侍剑回过身，转向身后的一个巨大的火炉，鼓动真气燃起了熊熊的大火。说：开始！\n",me );
	message_vision(BLU "$N双手握住一个巨大的铁锤，猛的向炉中渐渐红热起来的"+o_name+"挥去！\n" NOR,me);
	message_vision(RED "只听得棚的一声巨响，锤头和"+o_name+"粘在了一起。\n" NOR,me );
	message_vision(YEL "$N只觉得掌心一热，浑身的血液似乎都沸腾了起来！\n" NOR,me);
	message_vision(HIM "一身精血胶合着汩汩的内气，源源不断的向炉中的"+o_name+"涌去！\n" NOR,me );
	if( (me->query("qi"))<(me->query("max_qi")) || (me->query("jing"))<(me->query("max_jing")) || (me->query("neili"))<(me->query("max_neili")) )
	{
		message_vision(HIR "突然$N觉得气血一阵翻涌，一口真气接不上来。。。。 \n" NOR, me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision(HIR "只听咯的一声轻响，一柄巨剑从炉中倏然跃起。化作一道青电猛的向$N的前胸刺来！！\n" NOR,me );
	say("侍剑见状大叫：神剑初成，人血以祭！！闪开！\n");
	message_vision("$N只觉得眼前一花，一条白影迅捷无比的挡在了$N的身前。\n",me );	
	message_vision("巨剑透胸穿出，侍剑惨号一声，鲜血溅得你满脸都是！\n",me );
	message_vision(RED "侍剑脚下一个不稳，倒在了地上。侍剑已经奄奄一息了。\n" NOR,me);
	this_object()->set("max_qi",10);
	message_vision("巨剑又飞了起来，飞到半空，当的一声落回到地上。\n炉中的火灭了。一室的劲气化于无形，一切又归于沉寂。\n",me );
	
	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",0);

	me->set("weapon/make",1);		//武器制造后防止再造的标志		
	me->set("weapon/name",w_name);	//武器的名称
	me->set("weapon/id",id);		//武器的代号
	me->set("weapon/lv",1);    	//武器等级
	me->set("weapon/or",o_name);	//记录制造原料
	me->set("weapon/value",0);	      	//记录武器升级已有的点数	
	me->set("weapon/type","剑");
	me->set("weapon/time",make_time);

	sword=new("/d/suburb/fy/npc/m_weapon/weapon/m_sword",1);	//生成新剑
	sword->move(this_player());
	message_vision("侍剑摸起地上，带着斑斑血迹还有些烫手的巨剑，说：\n剑。。已。。成。。，侍剑的任务。。。也就完成了。。。。\n",me );
	say("侍剑艰难的说：剑。。您。。收好，我该走了。。。\n");
	message_vision("侍剑说完。倏的便不见了。\n",me);
	this_object()->die();
	return 1;
}

