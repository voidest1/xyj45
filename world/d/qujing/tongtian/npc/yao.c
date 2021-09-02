// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "鲤鱼精",
  "鲫鱼精",
  "鳖精",
  "鲇鱼精",
  "水螺精",
  "蚌壳精",
  "鳌精",
  "水鲑精",
  "河鳗精",
  "鲞精",
});

void create()
{
  int i = random(5)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"yao jing", "jing"}));
  set("gender", "男性");
  set("age", 10*i);
  set("attitude", "aggressive");
  set("combat_exp", 40000*i);
  set("per", 10);
  set_skill("parry", 20*i);
  set_skill("unarmed", 20*i);
  set_skill("dodge", 50*i);
  set_skill("blade", 20*i);
  set_skill("fork", 20*i);
  set_skill("mace", 20*i);
  set_skill("spear", 20*i);
  set_skill("sword", 20*i);
  set_skill("whip", 20*i);
  set_skill("axe", 20*i);
  set_skill("hammer", 20*i);
  set_skill("rake", 20*i);
  set_skill("stick", 20*i);
  set_skill("staff", 20*i);
  set_skill("dagger", 20*i);
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/tongtian/obj/armor")->wear();
  str = "/d/qujing/tongtian/obj/weapon0";
  str[strlen(str)-1] = '0'+random(4);
  carry_object(str)->wield();
}

