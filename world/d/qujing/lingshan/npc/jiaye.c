// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// snowcat 12 14 1997

inherit NPC;

#include <obstacle.h>

int do_tell ();

void create()
{
  set_name("迦叶尊者", ({ "jiaye zunzhe", "jiaye", "zunzhe" }));
  set("title", "灵山");
  set("gender", "男性");
  set("age", 1000);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 2000);
  set("max_gin", 2000);
  set("max_sen", 2000);
  set("force", 2000);
  set("max_force", 2000);
  set("force_factor", 80);
  set("max_mana", 2000);
  set("mana", 2000);
  set("mana_factor", 80);
  set("combat_exp", 1200000);
  set_skill("literate", 90);
  set_skill("spells", 90);
  set_skill("buddhism", 90);
  set_skill("unarmed", 90);
  set_skill("jienan-zhi", 90);
  set_skill("dodge", 90);
  set_skill("lotusmove", 90);
  set_skill("parry", 90);
  set_skill("force", 90);
  set_skill("lotusforce", 90);
  set_skill("staff", 90);
  set_skill("lunhui-zhang", 90);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("inquiry", ([
    "name" : "迦叶也。",
    "here" : "灵山也。",
    "灵山" : "我佛如来之灵山也。",
    "雷音寺" : "我佛如来之雷音寺也。",
    "西行" : (: do_tell :),
    "西天" : (: do_tell :),
    "求取真经" : (: do_tell :),
    "取经" : (: do_tell :),
    "真经" : (: do_tell :),
    "经" : (: do_tell :),
  ]));
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );

  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

void init ()
{
  call_out ("telling",10,this_player());
}

int do_tell ()
{
  call_out ("telling",1,this_player());
  return 1;
}

int telling (object who)
{
  object me = this_object();

  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  if(!who) return 1;

  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("obstacle/"+names[i])!="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
    tell_object (who,me->query("name")+
                     "告诉你：你西行求取真经已历尽了所有的难关。\n\n");
    who->set_temp("obstacle/lingshan_enter",1);
    if (environment(me)==environment(who) &&
        who->query("obstacle/reward") == 0)
      message_vision ("$N对$n一鞠躬：我佛有请！\n",me,who);
  }
  else
  {
    tell_object (who,me->query("name")+"告诉你：你西行求取真经还须过"+
                     chinese_number(nb)+"关：\n");
    strs = (string *)sort_array (strs, 1);
    for (i = 0; i < nb; i++)
    {
      tell_object (who,"    "+strs[i]+"\n");
    }
    tell_object (who,"\n");
  }
  return 1;
}
