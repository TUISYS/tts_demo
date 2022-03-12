#include "tui.h"

static char *tts_string = "��֮�����Ա��ơ��������ϰ��Զ�������̣�����Ǩ����֮��������ר������ĸ�����ڴ����Ӳ�ѧ���ϻ��̡����ɽ�����巽�������ӣ������"
                    "�����̣���֮�����̲��ϣ�ʦ֮�衣�Ӳ�ѧ�������ˡ��ײ�ѧ���Ϻ�Ϊ�����������������˲�ѧ����֪�塣Ϊ���ӣ�����ʱ����ʦ�ѣ�ϰ���ǡ�"
                    "����䣬����ϯ��Т���ף�����ִ�������꣬�����档���ڳ�������֪����Т㩣��μ��š�֪ĳ����ʶĳ�ġ�һ��ʮ��ʮ���١��ٶ�ǧ��ǧ����"
                    "�����ߣ�����ˡ������ߣ������ǡ������ߣ������塣�����ף���˳��Ի���ģ�Ի�ﶬ������ʱ���˲��Ի�ϱ���Ի���������ķ���Ӧ���С�"
                    "Իˮ��ľ�����������У���������ʮ���ߣ������ʮ��֧����������Ի�Ƶ���������Ի���������Ȩ������£���ů�������л����ڶ�����";
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

	/* �������� */
	sound = tui_sound_create(tui_layer_top());
	/* �������� */
	memset(&attri, 0, sizeof(tui_sound_attri_t));
	attri.cb = tui_tts_sound_cb;
	tui_sound_set_attri(sound, &attri);
	tui_sound_set_sound_src_one_hz(sound, tts_string + tts_cnt);
	tts_cnt += 2;
	tui_sound_play(sound);
}