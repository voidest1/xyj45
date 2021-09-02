// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
  set_name("宫卫", ({ "gong wei", "wei" }));
  set("age", 35);
  set("gender", "男性");
  set("attitude", "peaceful");
  set("str", 20);
  set("combat_exp", 20000);
  set("max_kee", 400);
  set("max_sen", 400);
  set("max_force", 200);
  set("force", 200);
  set("force_factor", 10);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("whip", 40);
  set_skill("force", 40);

  setup();
  carry_object("/d/obj/weapon/whip/tielian")->wield();
  carry_object("/d/obj/cloth/bingfu")->wear();
}


