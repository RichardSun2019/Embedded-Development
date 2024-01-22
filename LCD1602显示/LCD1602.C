//程序功能1602液晶第一行显示"0123456789ABCDEF";第二行显示"!@#$%^&*()<>{}?+";
#include "reg52.h"
#define uchar unsigned char 
#define uint unsigned int

sbit rs=P1^0;//H数据，L命令
sbit en=P2^5;//高脉冲使能，使能脉宽最小150ns
sbit rw=P1^1;
uchar code table[]="mcustudio.com.cn";
uchar code table1[]="TEL:159808545601";
uchar code table2[] = "0123456789abcdef";
void delay(uchar x)
{	uint y;
			for(;x>0;x--)
	 {									 
		for(y=100;y>0;y--)
				{};
	 }
}
void lcdwrdata(uchar dat)
{
   // dat = ((dat&0x01)<<7)|((dat&0x02)<<5)|((dat&0x04)<<3)|((dat&0x08)<<1)|((dat&0x10)>>1)|((dat&0x20)>>3)|((dat&0x40)>>5)|((dat&0x80)>>7);
	rs = 1;//写数据时RS拉高
	P0 = dat;
	delay(6);
	en = 1;
	delay(6);
	en = 0;
	delay(6);
}
void lcdwrcom(uchar cdat)//写指令数据到LCD  
{	
   // cdat = ((cdat&0x01)<<7)|((cdat&0x02)<<5)|((cdat&0x04)<<3)|((cdat&0x08)<<1)|((cdat&0x10)>>1)|((cdat&0x20)>>3)|((cdat&0x40)>>5)|((cdat&0x80)>>7);
  rs = 0;//写指令时RS拉低
	P0 = cdat;//
	delay(6);
	en = 1;
	delay(6);//不加此延时将导致不能写入指令，但能写入显示数据
	en = 0;
	delay(6);
}
void lcd_init()
{	
	lcdwrcom(0x38);//0x38设置显示模式为：16X2 显示,5X7 点阵,8 位数据接口
	lcdwrcom(0x0f);//打开显示光标闪烁
	lcdwrcom(0x06);//当读或写一个字符后地址指针加1, 且光标加1.
	//lcdwrcom(0x05);//当写一个字符, 整屏显示右移, 光标不动而屏幕动.
	//lcdwrcom(0x07);//当写一个字符, 整屏显示左移, 光标不动而屏幕动.
	lcdwrcom(0x01);//数据指针清零
}
void main()
{	uchar n;
  rw = 0; //写模式(写指令或写数据)
	delay(200);
	en = 0;
	delay(6);
	lcd_init();   //写指令必须有rs=0,rw=0,en=1;
	
	lcdwrcom(0x80);//这里设置数据指针在第一行第一列.每写一个字符, 指针加1;
	//由于RAM映射区域不连续, 不能从0--127一直写.
	for(n=32;n<48;n++)
	{
		//lcdwrdata(table[n]);
		lcdwrdata(n);
		delay(100);
	}
	lcdwrcom(0x80+0x40);
	for(n=48;n<64;n++)
	{
		//lcdwrdata(table[n]);
		lcdwrdata(n);
		delay(100);
	}
	
	lcdwrcom(0x01);
	lcdwrcom(0x80);
	for(n=64;n<80;n++)
	{
		//lcdwrdata(table[n]);
		lcdwrdata(n);
		delay(100);
	}
	
	lcdwrcom(0x80+0x40);
	for(n=80;n<96;n++)
	{
		//lcdwrdata(table[n]);
		lcdwrdata(n);
		delay(100);
	}

	//lcdwrcom(0x02);
	/*
	for(n=0;n<16;n++)
	{
		lcdwrdata(table1[n]);
		delay(100);
	}
	lcdwrcom(0x01);
	for(n=0;n<20;n++)
	{
		lcdwrdata(table2[n]);
		delay(100);
	}*/
	while(1)
	{
	}
}
