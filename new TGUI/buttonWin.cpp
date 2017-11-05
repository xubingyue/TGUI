#include "winClass.hpp"

buttonWin::buttonWin(
			uint16_t winXpos,
			uint16_t winYpos,
			uint16_t winWidth,
			uint16_t winHigh,
			char* name,
			uint8_t wsStyle,
			rootWin* parent,
			xQueueHandle queue
):controlWin(winXpos,winYpos,winWidth,winHigh,name,wsStyle,parent,queue)
{
	setTextColor(BLACK);
	setTextColor(WHITE);
}

buttonWin::~buttonWin()
{

}

//绘画 就自己 不同的窗口实现不同
void buttonWin::paintWin()
{	
	LCD_SetColors(getBackColor(),getBackColor());
	LCD_DrawFullRect(getAbsoluteX(),getAbsoluteY(),getWinWidth(),getWinHigh());
	LCD_SetColors(getTextColor(),getTextColor());
	LCD_DrawRect(getAbsoluteX(),getAbsoluteY(),getWinWidth(),getWinHigh());
	displayStrCenter(Font16x24,getTextColor(),getBackColor(),getWinName());
}

//按钮失焦
void buttonWin::defocusButton()
{
	//绘画成纯灰色
	LCD_SetColors(GREY,GREY);
	LCD_DrawFullRect(getAbsoluteX(),getAbsoluteY(),getWinWidth(),getWinHigh());
	LCD_SetColors(getTextColor(),getTextColor());
	LCD_DrawRect(getAbsoluteX(),getAbsoluteY(),getWinWidth(),getWinHigh());
	displayStrCenter(Font16x24,BLACK,GREY,getWinName());
}

//按钮按下
void buttonWin::pressButton()
{
	LCD_SetColors(WHITE,WHITE);
	LCD_DrawFullRect(getAbsoluteX(),getAbsoluteY(),getWinWidth(),getWinHigh());
	LCD_SetColors(getTextColor(),getTextColor());
	LCD_DrawRect(getAbsoluteX(),getAbsoluteY(),getWinWidth(),getWinHigh());
	displayStrCenter(Font16x24,getTextColor(),WHITE,getWinName());	
}



//按钮释放
void buttonWin::releaseButton()
{
	//重绘
	paintWin();
}

//激活控件--注册 中间会调用createWin（） 其他根据不同的窗口变化
void buttonWin::registerWin()
{
	rootWin::registerWin();
}

//注销控件  会调用destroy（）窗口 其他会根据不同窗口变化
void buttonWin::unregisterWin()
{
	rootWin::unregisterWin();
}

void buttonWin::destroyWin()
{
	rootWin::destroyWin();
}