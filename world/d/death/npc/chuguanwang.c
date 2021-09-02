// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("仵官王", ({"chuguan wang", "wang", "chuguan"}));
  set("title", "阴间十王之");
  set("gender", "男性");
  set("age", 60);
  set("class", "youling");
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30+random(5));
  set("max_kee", 800);
  set("max_gin", 800);
  set("max_sen", 500);
  set("force", 750);
  set("max_force", 1000);
  set("force_factor", 50);
  set("max_mana", 1000);
  set("mana", 1000);
  set("mana_factor", 50);
  set("combat_exp", 700000);
  set_skill("unarmed", 150);
  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("spells", 150);
  set_skill("jinghun-zhang", 120);
  set_skill("force", 150);
  set_skill("gouhunshu", 100);
  set_skill("ghost-steps", 100);
  set_skill("tonsillit", 100);
  map_skill("dodge", "ghost-steps");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  
  create_family("阎罗地府", 1, "你好");
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
}


