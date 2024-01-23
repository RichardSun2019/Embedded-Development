/*************************************************************
[�ļ���] C51����ң��Һ����ʾ���ֺ�
[����]	 1.���ֺ�(��ѡ����); 2.����ң��ѡ����; 3.1602LCD��������ʾ.
[ԭ��]	 

*************************************************************/
#include <REG52.H>
#include <INTRINS.H>
//#include <stdio.h>
#include <NOTE.H>
#include <string.h>

#define uchar unsigned char 
#define uint unsigned int
	
#define Imax 14000    //�˴�Ϊ����Ϊ11.0592ʱ��ȡֵ, 
#define Imin 8000    //��������Ƶ�ʵľ���ʱ,
#define Inum1 1450    //Ҫ�ı���Ӧ��ȡֵ��
#define Inum2 700 
#define Inum3 3000 

unsigned char f;
sbit Beep = P2^3;
unsigned int ni = 0;
unsigned int i=0;
unsigned int *pt = music_none; // ָ�����������ָ��;
unsigned char code table[]={0x0c,0x18,0x5e,0x08,0x1c,0x5a,0x42,0x52,0x4a }; //
unsigned char Im[4]={0x00,0x00,0x00,0x00};
unsigned long m,Tc;
unsigned char IrOK;

//1602LCD�趨:
sbit rs=P1^0;//H���ݣ�L����
sbit en=P2^5;//������ʹ�ܣ�ʹ��������С150ns
sbit rw=P1^1;
unsigned char code Song1[] = "Gu Yong Zhe     ";
unsigned char code Song2[] = "Chun Jie Xu Qu  ";
unsigned char code Song3[] = "Music Test      ";
unsigned char code Song4[] = "Nothing         ";

void int1()  interrupt 1   /*���ö�ʱ��0 ���ƽ��� ��interrupt0��1,2,3,4�ֱ��Ӧ���ж�0��
                              ��ʱ��0�����ж�1����ʱ��1�����п�*/   
{  TH0=0xd8;   		   
   TL0=0xef;   		
   ni--;   }	

void delay (unsigned int i)   //����Ƶ����ʱ�������ԣ���ʱʱ��=8i+2  us    
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

void read_sta()  //��״̬
{
	uint j=1000;//��ʱ����
	P0=0x80;
	rs=0;    //rs=0 rw=1 E=1 ��״̬
	rw=1;
	en=1;
	while((P0&0x80)&&j--)_nop_();//æ��ȴ�һ��nop���1us��������j=1000 ��1ms��ʱ�ж�
	en=0; //en���� 
}

void write_com(uchar com)
{
	//read_sta();  //��æ�ź�,�����������һ�����ܼ��������, ����LCD��ʾ����ȷ.
	rs=0;    		//д����rs=0 д����rs=1
	rw=0;      	//��,rw=0
	P0=com;  		//��Ҫд�����ݷŵ����ݿ�
	en=0; 		//Eһ��������дһ������ ��νһ�����������ָE��0->1->0��һ���͸ߵ͵ı任 ��������������en=0
	delayLCD(6);
	en=1;
	delayLCD(6);
	en=0;
}
void write_data(uchar dat)
{
	//read_sta();
	rs=1; //rs=1д����
	rw=0;
	P0=dat;
	en=0; //ͬ��
	delayLCD(6);
	en=1;
	delayLCD(6);
	en=0;
}
void lcd_init()
{
	write_com(0x38); //8λ���ݿڣ�������ʾ��5*7�����ַ�
	write_com(0x0f);   //����ʾ�����˸
	write_com(0x06);   //��дָ���1��Ļ���ƶ� 0101
	write_com(0x01);   //������귵��00Hλ��
}


//�ⲿ�жϽ������
void intersvr1(void) interrupt 2 using 1
{  //�ⲿ�ж�1����, �üĴ���1.
	//ע��һ�ν�����Ҫ��ε��ø��жϺ���
	int ic=0;
	
	ET0=0; 
		
		Tc = TH1*256 + TL1;                       //��ȡ�ж�ʱ����ʱ��
		TH1 = 0; 
    TL1 = 0;              									//��ʱ�ж���������
		if((Tc>Imin)&&(Tc<Imax))
   { //����ж�ʱ����8000~14000��, ��8ms--14ms��(�͵�ƽ��ʼ��, �½��ش���)
		 // �����Imax��Ϊ10000, �Ƿ�ͬ����Ч???
				m=0;
        f=1;
				return; 
	  }       //�ҵ���ʼ��
	 
		if(f==1)
	 {
        if(Tc>Inum1&&Tc<Inum3) 
			 {//1.45ms--3ms֮��, 		
						Im[m/8]=Im[m/8]>>1|0x80; 
						m++; 
			  }
			 
				if(Tc>Inum2&&Tc<Inum1) 
			 { // 0.7ms--1.45ms
						Im[m/8]=Im[m/8]>>1; 
						m++; //ȡ�� 
			  }
			 
				if(m==32) 
			 {		m=0;  
						f=0;
				 
						if(Im[2]==~Im[3]) 
					 {		
								IrOK=1; 
						}
						else {IrOK=0;ET0=1; }   //ȡ����ɺ��ж϶����Ƿ���ȷ
				}
               //׼������һ��
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
	
	
	
	//TMOD��Ĭ��ֵ(��λֵ)Ϊ0x00.
  TMOD=0x11;
	//���������صļĴ���(�����жϺ������õ���ʱ��1);
	m=0;
	f=0;
	
	//IE�Ĵ���:
	EA=1; //�ж�����;
	EX1=1;//IE�Ĵ���D2λ, INT1 �ж�����;
	ET0=1;
	//ET1=1;��ʱ���ж�����, �������ʱ������������.
	
	//�ж����ȼ��Ĵ���IP:
	IP=0x0c;
	//��ʱ�����ƼĴ���TCON:
	IT1=1;//NIT1, �ӱߴ����ж�, �½�����Ч;
	
	//��ʱ���Ĵ���TL0,TH0,TL1,TH1:
	TH0=0xd8;TL0=0xef;    /*��ʼֵ64535 ���ӵ�65535�����1ǧ�Σ���1ms��ʱΪһ����λ
                         ��������ʹ�á���12MHz����12��Ƶ��,�ڷ����������õ�*/
	TH1=0;TL1=0;   //��������õ�;
	TR1=1;
	
	
  Beep=1;					//1010 1010, ��ʱBeep���ڸߵ�ƽ, ������������. 
	
	//1602LCD��ʼ��:
	rw = 0;
	delayLCD(200);
	en = 0;
	lcd_init();   //дָ�������rs=0,rw=0,en=1;
	//while(1){}
	play:   				
	while(1)
	{
    a:if(pt==music_none) {Beep=1;delay(1000); goto play;}
		else{
			 p = pt[i];   
       if(p==0x00)       { i=0, delay(1000); goto play;}     //�������������,��ʱ1(������Ȼ����1)��,�ص���ʼ����һ��    
       else if(p==B4XZ) { i=i+2;Beep=1;delay(Z4); goto a;}
			 else if(p==B8XZ) { i=i+2;Beep=1;delay(Z8); goto a;}
				else if(p==0xff)  { i=i+1;delay(47600); goto a;}  //�������ķ���ֹ��,��ʱ455ms,����ȡ��һ����    
       else         		 {ki=pt[i++]/2, ni=pt[i++];}  //ȡƵ�ʳ��� �� ���ĳ������ο�ͨ������m�ı��������Ը��ĵ�ʽ   
					TR0=1;                                             //����ʱ��0   
	   //P2=~P2;							 //ledȡ����˸
        while(ni!=0) Beep=~Beep ,delay(ki);	 //��������while(n!=0)����������ʱֵ
		//�����൱��������ʱ��, һ������Ȼ���ŵļ�ʱ��n, ��һ����delay����, ����ָ��Beep�ķ�תƵ��, 
     //����, ���㹫ʽΪ f = 1/[(m*8+2)*10^-6]    
	       
       TR0=0;                                             //�ض�ʱ��1    
    }				   
	}
}
	










