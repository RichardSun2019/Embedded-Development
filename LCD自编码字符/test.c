#include <reg52.h>
#include <string.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char


sbit en=P2^5;    //E��������źŶ˿�
sbit rs=P1^0; //������ƶ˿�
sbit rw=P1^1; //��д���ƿ�

uchar t_code1[]={0x15,0x1F,0x04,0x04,0x1C,0x11,0x1F,0x00};//�Զ����һ��5*7���� ��ͼ��ı���
uchar t_code2[]={0x15,0x1F,0x04,0x00,0x04,0x1F,0x15,0x00};
uchar t_code3[]={0x04,0x04,0x1f,0x04,0x0a,0x1a,0x15,0x00};
uchar t_code4[]={0x0e,0x15,0x0e,0x1f,0x04,0x04,0x04,0x00};


void delay(unsigned char x)
{	unsigned int y;
	for(;x>0;x--) 
		for(y=100;y>0;y--){};
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
	read_sta();  //��æ�ź�
	rs=0;    		//д����rs=0 д����rs=1
	rw=0;      	//��,rw=0
	P0=com;  		//��Ҫд�����ݷŵ����ݿ�
	en=0; 		//Eһ��������дһ������ ��νһ�����������ָE��0->1->0��һ���͸ߵ͵ı任 ��������������en=0
	en=1;
	delay(6);
	en=0;
}
void write_data(uchar date)
{
	read_sta();
	rs=1; //rs=1д����
	rw=0;
	P0=date;
	en=0; //ͬ��
	en=1;
	delay(6);
	en=0;
}
void lcd_init()
{
	write_com(0x38); //8λ���ݿڣ�������ʾ��5*7�����ַ�
	write_com(0x0c);   //�޹�겻��˸
	write_com(0x06);   //��дָ���1��Ļ���ƶ� 0101
	write_com(0x01);   //������귵��00Hλ��
}
void main()
{
	uchar i;
	lcd_init();
	for(i=0;i<8;i++)
	{
	write_com(0x40+i); //��ַ 0x40-0x78 8����Ӧһ���ַ�
	write_data(t_code3[i]);
	}

	for(i=0;i<8;i++)
	{
	write_com(0x78+i); //��ַ 0x40-0x78 8����Ӧһ���ַ� д�ڰ˸��ַ�
	write_data(t_code4[i]);
	}

		for(i=0;i<16;i++)
	{
	write_com(0x80+i); //һ��
	write_data(0x00);  //0x00�ǵ�һ��
	}

	for(i=0;i<16;i++)
	{
	write_com(0x80+0x40+i); //�ڶ���
	write_data(0x07);  //0x07�ǵڵ�8����Ϊ�Ǵ�0��ʼ
	}
	while(1){	}
}