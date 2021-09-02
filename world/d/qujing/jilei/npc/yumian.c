// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("玉面公主", ({ "yumian gongzhu", "yumian", "gongzhu", "princess" }));
  set("title", "积雷山");   
  set("long", "一位娇柔万分的女子，伶俐地扭动着腰肢。\n");
  set("gender", "女性");
  set("age", 16);
  set("attitude", "heroism");
  set("per", 32);
  set("max_kee", 800);
  set("max_gin", 800);
  set("max_sen", 800);
  set("force", 700);
  set("max_force", 700);
  set("force_factor", 50);
  set("max_mana", 700);
  set("mana", 700);
  set("mana_factor", 50);
  set("combat_exp", 450000);
  set_skill("spells", 50);
  set_skill("moonshentong", 50);
  set_skill("unarmed", 50);
  set_skill("baihua-zhang", 50);
  set_skill("dodge", 50);
  set_skill("moondance", 50);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("moonforce", 50);
  set_skill("mace", 50);
  set_skill("wusi-mace", 50);
  map_skill("spells", "moonshentong");
  map_skill("unarmed", "baihua-zhang");
  map_skill("dodge", "moondance");
  map_skill("mace", "wusi-mace");
  map_skill("parry", "wusi-mace");
  map_skill("force", "moonforce");
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/jilei/obj/wufeng")->wield();
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/jilei_yumian_killed",1);
    call_out ("li_appearing",1,ob);
  }
  message_vision ("\n$N翻倒在地现了真身，竟是一只狐狸精。\n",me);
  message_vision ("狐狸精扑在地上，死了。\n\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void li_appearing (object who)
{
  object li = new ("/d/qujing/jilei/npc/li");

  li->announce_success (who);
  destruct (li); 
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);
  object niumo = present ("niumo wang", where);

  set_temp("my_killer",ob);
  ::kill_ob(ob);
  if (niumo && !niumo->is_fighting())
    niumo->kill_ob(ob);
}


