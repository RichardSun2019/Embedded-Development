/*程序说明： 
51单片机红外遥控解码程序
单片机采用外部中断INTI管脚和红外接收头的信号线相连，
中断方式为边沿触发方式。并用定时器0计算中断的间隔时间，
来区分前导码、二进制的1,0;8位操作码提取出来在数码管上显示。
 
解码值在Im[2]中，当IrOK=1时解码有效。 
用遥控器对准红外接收头，按下遥控器按键，在数码管的两位上就会显示对应按键的编码
*/
#include <reg52.h>
#include <intrins.h>
#include <string.h>
#define uchar unsigned char 
#define uint unsigned int
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
//sbit dula=P2^6;
//sbit wela=P2^7;
uchar code table[]={ 0x0c,0x18,0x5e,0x08,0x1c,0x5a,0x42,0x52,0x4a}; 
uchar f;

#define Imax 14000    //此处为晶振为11.0592时的取值, 
#define Imin 8000    //如用其它频率的晶振时,
#define Inum1 1450    //要改变相应的取值。
#define Inum2 700 
#define Inum3 3000 

unsigned char Im[4]={0x00,0x00,0x00,0x00};
uchar show[2]={0,0};
unsigned long m,Tc;
unsigned char IrOK;

//1602LCD设定:
sbit rs=P1^0;//H数据，L命令
sbit en=P2^5;//高脉冲使能，使能脉宽最小150ns
sbit rw=P1^1;
unsigned char code Song1[]="Gu Yong Zhe     ";
unsigned char code Song2[] = "Chun Jie Xu Qu  ";
unsigned char code Song3[] = "Music Test      ";
unsigned char code Song4[] = "Nothing         ";


void delayLCD(unsigned char x)
{	unsigned int y;
			for(;x>0;x--)
	 {									 
		for(y=100;y>0;y--)
				{};
	 }
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
	delayLCD(6);
	en=0;
}
void write_data(uchar dat)
{
	read_sta();
	rs=1; //rs=1写数据
	rw=0;
	P0=dat;
	en=0; //同上
	en=1;
	delayLCD(6);
	en=0;
}
void lcd_init()
{
	write_com(0x38); //8位数据口，两行显示，5*7点阵字符
	write_com(0x0f);   //打开显示光标闪烁
	write_com(0x06);   //读写指针加1屏幕不移动 0101
	write_com(0x01);   //清屏光标返回00H位置
}






//外部中断解码程序
void intersvr1(void) interrupt 2 using 1
{  //外部中断1允许, 用寄存器1.
		int ic;
		Tc = TH0*256 + TL0;                       //提取中断时间间隔时长
		TH0 = 0; 
    TL0 = 0;              									//定时中断重新置零
		if((Tc>Imin)&&(Tc<Imax))
   { //如果中断时间在8000~14000内, 即8ms--14ms内(低电平启始码, 下降沿触发)
		 // 如果把Imax改为10000, 是否同样有效???
				m=0;
        f=1;
				return; 
	  }       //找到启始码
	 
		if(f==1)
	 {
        if(Tc>Inum1&&Tc<Inum3) 
			 {//1.45ms--3ms之间, 		
						Im[m/8]=Im[m/8]>>1|0x80; 
						m++; 
			  }
			 
				if(Tc>Inum2&&Tc<Inum1) 
			 { // 0.7ms--1.45ms
						Im[m/8]=Im[m/8]>>1; 
						m++; //取码 
			  }
			 
				if(m==32) 
			 {		m=0;  
						f=0;
				 
						if(Im[2]==~Im[3]) 
					 {		
								IrOK=1; 
						}
						else IrOK=0;   //取码完成后判断读码是否正确
				}
               //准备读下一码
   }
	 if(IrOK==1){
			write_com(0x80);
			if(Im[2]==table[0]) 
				{	
					for(ic=0;ic<16;ic++)
					{ write_data(Song1[ic]);}
				}
			else if(Im[2]==table[1]) 
				{	
					for(ic=0;ic<16;ic++)
					{ write_data(Song2[ic]);}
				}
			else if(Im[2]==table[2]) 
			{		
					for(ic=0;ic<16;ic++)
					{ write_data(Song3[ic]);	}
			}
			else 
			{	
				for(ic=0;ic<16;ic++)
					{ write_data(Song4[ic]);	}
			}
			IrOK=0;
	}
}

/*演示主程序*/
void main()
{   
		m=0;
    f=0;
		EA=1;			//IE寄存器最高位, 中断允许;
		IT1=1;		//NIT1, 延边触发中断, 下降沿有效;
		EX1=1;		//IE寄存器D2位, INT1 中断允许;
 
		TMOD=0x11;		//定时器工作方式寄存器, 高4位管理 T1, 低4位管理 T0;
									//0001 0001, M1M0=01表示T0, T1均为16位定时器/计数器, C/T位为0,是定时器. 
									//T0 的启停由软件设置 TR0 实现。TR0 = 1： 启动定时/ 计数器 T0； TR0 = 0： 停止定时/ 计数器 T0 .
		TH0=0;
		TL0=0;
		TR0=1;//ET0=1;计时器仅用来计数.
	
	rw = 0;
	delayLCD(200);
	en = 0;
	lcd_init();   //写指令必须有rs=0,rw=0,en=1;

		while(1)
	 {		}
}

