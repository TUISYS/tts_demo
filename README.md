<h1 align="center"> TUI TTS中文语音合成测试用例 </h1>

## 描述
TUI *V2.1* 以上版本支持`TTS`中文语音合成。<br>
`TUISYS/tts_demo`仓库提供了gb2312编码转换语音的demo，实际应用要结合`TUISYS/tui_project`仓库里面的tui库文件，在tui内核初始化完成后调用。<br>
直接在应用里面调用sound控件的函数`int tui_sound_set_sound_src_one_hz(tui_obj_t *sound, const char *gb2312_one_zh);`。

## TTS资源
将仓库里面文件夹`tts_res`内容，通过EUIStudio工具导入到`其他资源`，TUI就可以调用sound控件，实现文字转语音播报。

## 接口函数
`int tui_sound_set_sound_src_one_hz(tui_obj_t *sound, const char *gb2312_one_zh);`函数只能播放一个中文汉字，播放完成后会通过控件回调函数，通知应用播放结束，这时候应用就可以设置下个播放汉字了。

