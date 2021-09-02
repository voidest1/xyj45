// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("殿官", ({ "dian guan", "guan" }) );
  set("gender", "男性");
  set("age", 40);
  set("combat_exp", 100000+random(20000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 400);
  set("max_gin", 400);
  set("force", 400);
  set("max_force", 400);
  set("force_factor", random(30)+15);
  set_skill("unarmed", 40);
  set_skill("parry", 40);
  set_skill("dodge", 40);
  set_skill("blade", 40);

  setup();

  carry_object("/d/obj/cloth/gongpao")->wear();
}

