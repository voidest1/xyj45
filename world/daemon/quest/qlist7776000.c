#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "葛伦",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "九环禅杖",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "卜鹰",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "圆月弯刀",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "白袍公",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "黑袍公",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "黑棋子",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "白棋子",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "白布袍",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "黑布袍",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "紫斑巨蟒",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "小石子",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "青竹先生",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "寒梅先生",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "孤松先生",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "活佛",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "守护天王",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "持国天王",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "增长天王",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "广目天王",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "青色宝剑",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "赖吒刀",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "博叉赤索",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "毗沙门塔",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "兴国大师",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                HIY "金光禅杖" NOR,
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "打更的",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "魅影神巾",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "水母阴姬",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "魅影神带",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "魅影神衣",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "魅影神靴",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "溅满血的黑袍",
                "quest_type":           "寻",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "曲无容",
                "quest_type":           "杀",
                "exp_bonus":            70,
        ]),

});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
