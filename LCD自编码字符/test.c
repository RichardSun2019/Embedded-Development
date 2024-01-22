#include <reg52.h>
#include <string.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char


sbit en=P2^5;    //E脉冲控制信号端口
sbit rs=P1^0; //命令控制端口
sbit rw=P1^1; //读写控制口

uchar t_code1[]={0x15,0x1F,0x04,0x04,0x1C,0x11,0x1F,0x00};//自定义的一个5*7点阵 截图里的编码
uchar t_code2[]={0x15,0x1F,0x04,0x00,0x04,0x1F,0x15,0x00};
uchar t_code3[]={0x04,0x04,0x1f,0x04,0x0a,0x1a,0x15,0x00};
uchar t_code4[]={0x0e,0x15,0x0e,0x1f,0x04,0x04,0x04,0x00};


void delay(unsigned char x)
{	unsigned int y;
	for(;x>0;x--) 
		for(y=100;y>0;y--){};
}

void read_sta()  //读状态
{
	uint j=1000;//超时变量
	P0=0x80;
	rs=0;    //rs=0 rw=1 E=1 读状态
	rw=1;
	en=1;
	while((P0&0x80)&&j--)_nop_();//忙则等待一个nop大概1us配合上面的j=1000 做1ms超时判断
	en=0; //en拉低 
}

void write_com(uchar com)
{
	read_sta();  //读忙信号
	rs=0;    		//写命令rs=0 写数据rs=1
	rw=0;      	//读,rw=0
	P0=com;  		//把要写的数据放到数据口
	en=0; 		//E一个正脉冲写一个数据 所谓一个正脉冲就是指E从0->1->0的一个低高低的变换 所以这里先拉低en=0
	en=1;
	delay(6);
	en=0;
}
void write_data(uchar date)
{
	read_sta();
	rs=1; //rs=1写数据
	rw=0;
	P0=date;
	en=0; //同上
	en=1;
	delay(6);
	en=0;
}
void lcd_init()
{
	write_com(0x38); //8位数据口，两行显示，5*7点阵字符
	write_com(0x0c);   //无光标不闪烁
	write_com(0x06);   //读写指针加1屏幕不移动 0101
	write_com(0x01);   //清屏光标返回00H位置
}
void main()
{
	uchar i;
	lcd_init();
	for(i=0;i<8;i++)
	{
	write_com(0x40+i); //地址 0x40-0x78 8个对应一个字符
	write_data(t_code3[i]);
	}

	for(i=0;i<8;i++)
	{
	write_com(0x78+i); //地址 0x40-0x78 8个对应一个字符 写第八个字符
	write_data(t_code4[i]);
	}

		for(i=0;i<16;i++)
	{
	write_com(0x80+i); //一行
	write_data(0x00);  //0x00是第一个
	}

	for(i=0;i<16;i++)
	{
	write_com(0x80+0x40+i); //第二行
	write_data(0x07);  //0x07是第第8个因为是从0开始
	}
	while(1){	}
}