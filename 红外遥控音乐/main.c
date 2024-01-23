/*************************************************************
[文件名] C51红外遥控液晶显示音乐盒
[功能]	 1.音乐盒(可选音乐); 2.红外遥控选歌曲; 3.1602LCD歌曲名显示.
[原理]	 

*************************************************************/
#include <REG52.H>
#include <INTRINS.H>
//#include <stdio.h>
#include <NOTE.H>
#include <string.h>

#define uchar unsigned char 
#define uint unsigned int
	
#define Imax 14000    //此处为晶振为11.0592时的取值, 
#define Imin 8000    //如用其它频率的晶振时,
#define Inum1 1450    //要改变相应的取值。
#define Inum2 700 
#define Inum3 3000 

unsigned char f;
sbit Beep = P2^3;
unsigned int ni = 0;
unsigned int i=0;
unsigned int *pt = music_none; // 指向乐谱数组的指针;
unsigned char code table[]={0x0c,0x18,0x5e,0x08,0x1c,0x5a,0x42,0x52,0x4a }; //
unsigned char Im[4]={0x00,0x00,0x00,0x00};
unsigned long m,Tc;
unsigned char IrOK;

//1602LCD设定:
sbit rs=P1^0;//H数据，L命令
sbit en=P2^5;//高脉冲使能，使能脉宽最小150ns
sbit rw=P1^1;
unsigned char code Song1[] = "Gu Yong Zhe     ";
unsigned char code Song2[] = "Chun Jie Xu Qu  ";
unsigned char code Song3[] = "Music Test      ";
unsigned char code Song4[] = "Nothing         ";

void int1()  interrupt 1   /*采用定时器0 控制节拍 。interrupt0，1,2,3,4分别对应外中断0、
                              定时器0、外中断1、定时器1、串行口*/   
{  TH0=0xd8;   		   
   TL0=0xef;   		
   ni--;   }	

void delay (unsigned int i)   //控制频率延时，经调试，延时时间=8i+2  us    
{      
 while(--i);   
}  

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
	//read_sta();  //读忙信号,但是这个任务一定不能加这个函数, 否则LCD显示不正确.
	rs=0;    		//写命令rs=0 写数据rs=1
	rw=0;      	//读,rw=0
	P0=com;  		//把要写的数据放到数据口
	en=0; 		//E一个正脉冲写一个数据 所谓一个正脉冲就是指E从0->1->0的一个低高低的变换 所以这里先拉低en=0
	delayLCD(6);
	en=1;
	delayLCD(6);
	en=0;
}
void write_data(uchar dat)
{
	//read_sta();
	rs=1; //rs=1写数据
	rw=0;
	P0=dat;
	en=0; //同上
	delayLCD(6);
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
	//注意一次解码需要多次调用该中断函数
	int ic=0;
	
	ET0=0; 
		
		Tc = TH1*256 + TL1;                       //提取中断时间间隔时长
		TH1 = 0; 
    TL1 = 0;              									//定时中断重新置零
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
						else {IrOK=0;ET0=1; }   //取码完成后判断读码是否正确
				}
               //准备读下一码
   }
	 if(IrOK==1){
		  write_com(0x01);
			
			if(Im[2]==table[0]) 
				{	pt=music_Guyongzhe;
					write_com(0x80);
					for(ic=0;ic<16;ic++)
					{ write_data(Song1[ic]);}
				}
			else if(Im[2]==table[1]) 
				{	pt=music_Chunjie;
					write_com(0x80);
					for(ic=0;ic<16;ic++)
					{ write_data(Song2[ic]);}
				}
			else if(Im[2]==table[2]) 
			{		pt=music_test;
					write_com(0x80);
					for(ic=0;ic<16;ic++)
					{ write_data(Song3[ic]);	}
			}
			else 
			{	pt=music_none;
				write_com(0x80);
				for(ic=0;ic<16;ic++)
					{ write_data(Song4[ic]);	}
			}
		IrOK=0;
		i=0;
		ET0=1; 
	 }
}


void main()
{
	unsigned int p;
	unsigned int ki;
	
	
	
	//TMOD的默认值(复位值)为0x00.
  TMOD=0x11;
	//定义红外相关的寄存器(红外中断函数中用到记时器1);
	m=0;
	f=0;
	
	//IE寄存器:
	EA=1; //中断允许;
	EX1=1;//IE寄存器D2位, INT1 中断允许;
	ET0=1;
	//ET1=1;定时器中断允许, 但这里计时器仅用来计数.
	
	//中断优先级寄存器IP:
	IP=0x0c;
	//定时器控制寄存器TCON:
	IT1=1;//NIT1, 延边触发中断, 下降沿有效;
	
	//定时器寄存器TL0,TH0,TL1,TH1:
	TH0=0xd8;TL0=0xef;    /*初始值64535 ，加到65535溢出，1千次，即1ms定时为一个单位
                         ，供节拍使用。（12MHz晶振，12分频）,在蜂鸣器部分用到*/
	TH1=0;TL1=0;   //红外接收用到;
	TR1=1;
	
	
  Beep=1;					//1010 1010, 此时Beep处于高电平, 蜂鸣器不工作. 
	
	//1602LCD初始化:
	rw = 0;
	delayLCD(200);
	en = 0;
	lcd_init();   //写指令必须有rs=0,rw=0,en=1;
	//while(1){}
	play:   				
	while(1)
	{
    a:if(pt==music_none) {Beep=1;delay(1000); goto play;}
		else{
			 p = pt[i];   
       if(p==0x00)       { i=0, delay(1000); goto play;}     //如果碰到结束符,延时1(这里显然不是1)秒,回到开始再来一遍    
       else if(p==B4XZ) { i=i+2;Beep=1;delay(Z4); goto a;}
			 else if(p==B8XZ) { i=i+2;Beep=1;delay(Z8); goto a;}
				else if(p==0xff)  { i=i+1;delay(47600); goto a;}  //若碰到四分休止符,延时455ms,继续取下一音符    
       else         		 {ki=pt[i++]/2, ni=pt[i++];}  //取频率常数 和 节拍常数本段可通过更改m的倍数，调试更改调式   
					TR0=1;                                             //开定时器0   
	   //P2=~P2;							 //led取反闪烁
        while(ni!=0) Beep=~Beep ,delay(ki);	 //！！！用while(n!=0)控制音符的时值
		//这里相当于两个计时器, 一个是自然流逝的计时器n, 另一个是delay函数, 用来指定Beep的翻转频率, 
     //其中, 计算公式为 f = 1/[(m*8+2)*10^-6]    
	       
       TR0=0;                                             //关定时器1    
    }				   
	}
}
	










