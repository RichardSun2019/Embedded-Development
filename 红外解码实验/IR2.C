/*程序说明： 
51单片机红外遥控解码程序
单片机采用外部中断INTI管脚和红外接收头的信号线相连，
中断方式为边沿触发方式。并用定时器0计算中断的间隔时间，
来区分前导码、二进制的1,0;8位操作码提取出来在数码管上显示。
 
解码值在Im[2]中，当IrOK=1时解码有效。 
用遥控器对准红外接收头，按下遥控器按键，在数码管的两位上就会显示对应按键的编码
*/
#include <reg52.h>
#define uchar unsigned char 
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
//sbit dula=P2^6;
//sbit wela=P2^7;
/*uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,
                        0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};*/
uchar code table[]={ 0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,
												0x01,0x19,0x11,0xc1,0x63,0x85,0x21,0x71}; 
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
sbit lcden=P2^5;//高脉冲使能，使能脉宽最小150ns
sbit rw=P1^1;
unsigned char code table1[]="Gu Yong Zhe";
unsigned char code table2[] = "Chun Jie Xu Qu";
unsigned char code table3[] = "Music Test";
unsigned char code table4[] = "Nothing   ";


void delayLCD(unsigned char x)
{	unsigned int y;
			for(;x>0;x--)
	 {									 
		for(y=100;y>0;y--)
				{};
	 }
}

void lcdwrdata(unsigned char dat)
{
   // dat = ((dat&0x01)<<7)|((dat&0x02)<<5)|((dat&0x04)<<3)|((dat&0x08)<<1)|((dat&0x10)>>1)|((dat&0x20)>>3)|((dat&0x40)>>5)|((dat&0x80)>>7);
	rs = 1;//写数据时RS拉高
	lcden = 1;
	P0 = dat;
	delayLCD(6);
	lcden = 0;
	delayLCD(6);
}
void lcdwrcom(unsigned char cdat)//写指令数据到LCD  
{	
   // cdat = ((cdat&0x01)<<7)|((cdat&0x02)<<5)|((cdat&0x04)<<3)|((cdat&0x08)<<1)|((cdat&0x10)>>1)|((cdat&0x20)>>3)|((cdat&0x40)>>5)|((cdat&0x80)>>7);
  rs = 0;//写指令时RS拉低
	lcden = 1;
  P0 = cdat;//
	delayLCD(6);//不加此延时将导致不能写入指令，但能写入显示数据
	lcden = 0;
	delayLCD(6);
}
void lcd_init()
{
	lcdwrcom(0x38);//0x38设置显示模式为：16X2 显示,5X7 点阵,8 位数据接口
	lcdwrcom(0x0e);//打开显示光标闪烁
	lcdwrcom(0x06);//当读或写一个字符后地址指针加1, 且光标加1.
	lcdwrcom(0x01);//数据指针清零
}


void delay(uchar i)
{
  uchar j,k,l; 
  for(j=i;j>0;j--)
    for(k=250;k>0;k--)
			for(l=250;l>0;l++);
}

void display()
{ int k=200;
   //P2_0 = 0;P2_1 = 1;P2_2 = 1;P2_3 = 1;//只有一位数码管, 用不到位选.
   P0=table[show[0]];
   delay(k);
	 P0=table[show[1]];
	 delay(k);
	 P0=0xfd;
	 delay(k);
/* 因为我们的小车只有一位数码管, 所以这个不需要显示.
   P2_0 = 1;P2_1 = 0;P2_2 = 1;P2_3 = 1;
   P0=table[show[1]];
   delay(2);
*/
  /* dula=0;
   P0=table[show[1]];
   dula=1;
   dula=0;
   
   wela=0;
   P0=0xfd;
   wela=1;
   wela=0;
   delay(5);
   
   P0=table[show[0]];
   dula=1;
   dula=0;
   
   P0=0xfe;
   wela=1;
   wela=0;
   delay(5);*/
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
			if(Im[2]==table[0]) 
				{	
					for(ic=0;ic<10;ic++)
					{ lcdwrdata(table1[ic]);
						delayLCD(10);
					}
				}
			else if(Im[2]==table[1]) 
				{	
					for(ic=0;ic<10;ic++)
					{ lcdwrdata(table2[ic]);
						delayLCD(10);
					}
				}
			else if(Im[2]==table[2]) 
			{	
					for(ic=0;ic<10;ic++)
					{ lcdwrdata(table3[ic]);
						delayLCD(10);
					}
			}
			else 
			{	
				for(ic=0;ic<10;ic++)
					{ lcdwrdata(table4[ic]);
						delayLCD(10);
					}
			}
			IrOK=0;
}
}

/*演示主程序*/
void main()
{
		unsigned int  a;
   
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
		TR0=1;//ET0=1;
	
	rw = 0;
	delayLCD(200);
	lcden = 0;
	lcd_init();   //写指令必须有rs=0,rw=0,lcden=1;
	lcdwrcom(0x00|0x80);

		while(1)
	 {

				if(IrOK==1) 
			 {
						show[1] = Im[2] & 0x0F;     //取键码的低四位
						show[0] = Im[2] >> 4;  
						IrOK = 0;
				}
						 
				for(a=100;a>0;a--)
			 {
						display();
				}
		}
}

