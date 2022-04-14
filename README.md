<h1 align="center"> TUI TTS中文语音合成测试用例 </h1>

## 描述
TUI *V2.1* 以上版本支持`TTS`中文语音合成，TTS算法只占用ROM空间2.75MB， RAM空间46.6KB。<br>
`TUISYS/tts_demo`仓库提供了gb2312编码转换语音的demo，实际应用要结合`TUISYS/tui_project`仓库里面的tui库文件，在tui内核初始化完成后调用。<br>
直接在应用里面调用sound控件的函数`int tui_sound_set_sound_src_one_hz(tui_obj_t *sound, const char *gb2312_one_zh);`。

## TTS资源
将仓库里面文件夹`tts_res`内容，通过uistudio工具导入到`其他资源`，TUI就可以调用sound控件，实现文字转语音播报。

## 接口函数
`int tui_sound_set_sound_src_one_hz(tui_obj_t *sound, const char *gb2312_one_zh);`函数只能播放一个中文汉字，播放完成后会通过控件回调函数，通知应用播放结束，这时候应用就可以设置下个播放汉字了。<br>
测试程序如下：
``` c
#include "tui.h"

static char *tts_string = "人之初，性本善。性相近，习相远。苟不教，性乃迁。教之道，贵以专。昔孟母，择邻处。子不学，断机杼。窦燕山，有义方。教五子，名俱扬。"
                    "养不教，父之过。教不严，师之惰。子不学，非所宜。幼不学，老何为。玉不琢，不成器。人不学，不知义。为人子，方少时。亲师友，习礼仪。"
                    "香九龄，能温席。孝于亲，所当执。融四岁，能让梨。弟于长，宜先知。首孝悌，次见闻。知某数，识某文。一而十，十而百。百而千，千而万。"
                    "三才者，天地人。三光者，日月星。三纲者，君臣义。父子亲，夫妇顺。曰春夏，曰秋冬。此四时，运不穷。曰南北，曰西东。此四方，应乎中。"
                    "曰水火，木金土。此五行，本乎数。十干者，甲至癸。十二支，子至亥。曰黄道，日所躔。曰赤道，当中权。赤道下，温暖极。我中华，在东北。";
static int tts_cnt = 0;
static void tui_tts_sound_cb(tui_obj_t *obj, tui_event_e event)
{
	if (event == TUI_EVENT_SOUND_PLAY_END) {
		tui_sound_set_sound_src_one_hz(obj, tts_string + tts_cnt);
		tts_cnt += 2;
		if (strlen(tts_string) < tts_cnt)
			tui_obj_del(obj);
		else
			tui_sound_play(obj);

	}
}

void tui_tts_speak_test(void)
{
	tui_sound_attri_t attri = { 0 };
	tui_obj_t * sound;

	/* 创建对象 */
	sound = tui_sound_create(tui_layer_top());
	/* 设置属性 */
	memset(&attri, 0, sizeof(tui_sound_attri_t));
	attri.cb = tui_tts_sound_cb;
	tui_sound_set_attri(sound, &attri);
	tui_sound_set_sound_src_one_hz(sound, tts_string + tts_cnt);
	tts_cnt += 2;
	tui_sound_play(sound);
}
```
