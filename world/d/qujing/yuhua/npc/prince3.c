// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 12/8/1997

inherit NPC;

void create()
{
  set_name("小王子", ({"xiao wangzi", "wangzi", "wang", "zi"}));
  set("title", "玉华县");
  set("gender", "男性");
  set("age", 15);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 100000);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("staff", 70);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",400);
  set("max_mana",400);
  set("force_factor",30);
  set("eff_dx",8000);
  set("nkgain",30);
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
}

int accept_object (object who, object ob)
{
  object me = this_object();
  string id = "xiao xiangyao zhang";

  if (ob->query("id") != id)
  {
    message_vision ("$N对$n摇头说道：不要不要。\n",me,who);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$N摇头说道：$n道行不够也，这玩意怕是有假。\n",me,who);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  if (present(id,me))
  {
    message_vision ("$N对$n摇头说道：我已有了，您那或许是假货也。\n",me,who);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  message_vision ("$N失声叫道："+ob->query("name")+"久寻不得也。\n",me,who);
  message_vision ("$N说道：多谢多谢！\n",me);
  who->set_temp("obstacle/yuhua_zhang",1);
  call_out ("wield_me",1,ob);
  return 1;
}

void return_ob (object ob, object who)
{
  if (ob)
    command ("give "+ob->query("id")+" to "+who->query("id"));
}

void wield_me (object ob)
{
  if (ob)
    command ("wield "+ob->query("id"));
}
