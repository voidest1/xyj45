// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zui-gun.c -少林醉棍

inherit SKILL;

mapping *action = ({
([	"action":"「蓝采和，提篮劝酒醉朦胧」，$N手中$w半提，缓缓划向$n的$l",
	"force" : 180,
        "dodge" : 0,
        "parry" : 5,
	"damage": 10,
	"lvl" : 10,
	"skill_name" : "蓝采和，提篮劝酒醉朦胧",
	"damage_type":"挫伤"
]),
([	"action":"「何仙姑，拦腰敬酒醉仙步」，$N左掌护胸，右臂挟棍猛地扫向$n的腰间",
	"force" : 200,
        "dodge" : 5,
        "parry" : 10,
	"damage": 15,
	"lvl" : 20,
	"skill_name" : "何仙姑，拦腰敬酒醉仙步",
	"damage_type":"挫伤"
]),
([	"action":"「曹国舅，千杯不醉倒金盅」，$N倒竖$w，指天打地，向$n的$l劈去",
	"force" : 230,
        "dodge" : 5,
        "parry" : 5,
	"damage": 20,
	"lvl" : 30,
	"skill_name" : "曹国舅，千杯不醉倒金盅",
	"damage_type":"挫伤"
]),
([	"action":"「韩湘子，铁棍提胸醉拔萧」，$N横提$w，棍端划了个半圈，击向$n的$l",
	"force" : 270,
        "dodge" : 5,
        "parry" : 5,
	"damage": 25,
	"lvl" : 40,
	"skill_name" : "韩湘子，铁棍提胸醉拔萧",
	"damage_type":"挫伤"
]),
([	"action":"「汉钟离，跌步翻身醉盘龙」，$N手中棍花团团，疾风般向卷向$n",
	"force" : 320,
        "dodge" : 10,
        "parry" : 15,
	"damage": 30,
	"lvl" : 50,
	"skill_name" : "汉钟离，跌步翻身醉盘龙",
	"damage_type":"挫伤"
]),
([	"action":"「铁拐李，踢倒金山醉玉池」，$N单腿支地，一腿一棍齐齐击向$n的$l",
	"force" : 380,
        "dodge" : 5,
        "parry" : 15,
	"damage": 35,
	"lvl" : 55,
	"skill_name" : "铁拐李，踢倒金山醉玉池",
	"damage_type":"挫伤"
]),
([	"action":"「张果老，醉酒抛杯倒骑驴」，$N扭身反背，$w从胯底钻出，戳向$n的胸口",
	"force" : 450,
        "dodge" : 5,
        "parry" : 20,
	"damage": 40,
	"lvl" : 60,
	"skill_name" : "张果老，醉酒抛杯倒骑驴",
	"damage_type":"挫伤"
]),
([	"action":"「吕洞宾，酒醉提壶力千钧」，$N腾空而起，如山棍影，疾疾压向$n",
	"force" : 530,
        "dodge" : 10,
        "parry" : 25,
	"damage": 50,
	"lvl" : 64,
	"skill_name" : "吕洞宾，酒醉提壶力千钧",
	"damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return (usage == "club") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        if (!me) me = this_object();
	level   = (int) me->query_skill("zui-gun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练少林醉棍。\n");
	me->receive_damage("kee", 25);
	return 1;
}
