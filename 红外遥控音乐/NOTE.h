#ifndef __NOTE_H__
#define __NOTE_H__


/*********** ���ʱ�׼��A-la-440HZ(DoΪ261.6HZ), ��������������, ����������Ϊ2��1/12�η� *************/
/*     ���㹫ʽΪ440HZ*2^(i/12), ����iΪ��������La���ı�׼Hash����       */
/***************************    C�������Ƶ��    **********************************/
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So		So#	 La 	La#	 Si
                1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
����Ƶ�ʣ�   ��	262  277  294  311  330  349  370  392  415  440  466  494
����Ƶ�ʣ�   ��	523  554  587  622  659  698  740  784  831  880  932  988 
����Ƶ�ʣ�   ��	1046 1109 1175 1245 1318 1397 1480 1568 1661 1760 1865 1976 
*/
/***************************    D�������Ƶ��    **********************************/
/*  	          Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So		So#	 La 	La#	 Si
                1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
����Ƶ�ʣ�   ��	294  311  330  349  370  392  415  440  466  494  523  554
����Ƶ�ʣ�   ��	587  622  659  698  740  784  831  880  932  988  1046 1109 
����Ƶ�ʣ�   ��	1175 1245 1318 1397 1480 1568 1661 1760 1865 1976 2093 2217 
*/

/***************************    G�������Ƶ��    **********************************/
/*  	          Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So		So#	 La 	La#	 Si
                1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
����Ƶ�ʣ�   ��	392  415  440  466  494  523  554  587  622  659  698  740
����Ƶ�ʣ�   ��	784  831  880  932  988  1046 1109 1175 1245 1318 1397 1480
����Ƶ�ʣ�   ��	1568 1661 1760 1865 1976 2093 2217 2349 2489 2637 2794 2960
*/

/***************************    B�������Ƶ��    **********************************/
/*  	          Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So		So#	 La 	La#	 Si
                1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
����Ƶ�ʣ�   ��	494  523  554  587  622  659  698  740  784  831  880  932  
����Ƶ�ʣ�   ��	988  1046 1109 1175 1245 1318 1397 1480 1568 1661 1760 1865 
����Ƶ�ʣ�   ��	1976 2093 2217 2349 2489 2637 2794 2960 3136 3322 3520 3729
*/


/*************** C������׺궨��	��0���������1�������**********************************/
/***********   ÿ��������Ӧ����������m(����ʱʱ��=8i+2  usʱ), �õ�1/f= 0.5*(8*m+2)*0.000001*1.085 *********/										
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So	  So#	 La 	La#	 Si
								1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
����������8us��	880, 831, 784, 740, 699, 660, 623, 588, 555, 523, 494, 466 
����������8us��	440, 415, 392, 370, 349, 330, 311, 294, 277, 262, 247, 233 
����������8us��	220, 208, 196, 185, 175, 165, 155, 147, 138, 131, 123, 116  */

#define CDo0 880
#define	CDo  440
#define CDo1 220
#define CDo11 100

#define CDo0L 831
#define	CDoL  415
#define CDo1L 208

#define Cre0  784
#define Cre   392
#define Cre1  196

#define Cmi0  699
#define Cmi   349
#define Cmi1  175

#define Cfa0  660
#define Cfa   330
#define Cfa1  165

#define Cso0  588
#define Cso   294
#define Cso1  147

#define Cla0  523
#define Cla   262
#define Cla1  131

#define Csi0  466
#define Csi   233
#define Csi1  116 


/*************** D������׺궨��	��0���������1�������**********************************/									
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So	  So#	 La 	La#	 Si
								1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
����������8us��	784, 740, 699, 660, 623, 588, 555, 523, 494, 466, 440, 415
����������8us��	392, 370, 349, 330, 311, 294, 277, 262, 247, 233, 220, 208 
����������8us��	196, 185, 175, 165, 155, 147, 138, 131, 123, 116, 110, 104  */

#define Do0 850	 //doΪר��ָ���˸�Ϊ��дD
#define	Do  424
#define Do1 212
#define Do11 106

#define re0  575
#define re   378
#define re1  189
#define re11 94

#define mi0  674
#define mi   337
#define mi1  168

#define fa0  636
#define fa   318
#define fa1  159

#define so0  567
#define so   283
#define so1  141

#define la0  505
#define la   252
#define la1  126

#define si0  450
#define si   224
#define si1  112  

/*************** G������׺궨��	��0���������1�������**********************************/									
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So	  So#	 La 	La#	 Si
								1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
����������8us��	588, 555, 523, 494, 466, 440, 415, 392, 370, 349, 330, 311
����������8us��	294, 277, 262, 247, 233, 220, 208, 196, 185, 175, 165, 155 
����������8us��	147, 138, 131, 123, 116, 110, 104, 98,  92,  87,  82,  78  */

#define GDo0 588
#define GDo	 294
#define GDo1 147
#define GDo11 74

#define Gre0 523
#define Gre  262
#define Gre1 131
#define Gre11 70

#define Gmi0 466
#define Gmi  233
#define Gmi1 116

#define Gfa0 440
#define Gfa  220
#define Gfa1 110

#define Gso0 392
#define Gso  196
#define Gso1 98

#define Gla0 349
#define Gla  175
#define Gla1 87

#define Gsi0  311
#define Gsi   155
#define Gsi1  78

/*************** B������׺궨��	��0���������1�������**********************************/									
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So	  So#	 La 	La#	 Si
								1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
����������8us��	466, 440, 415, 392, 370, 349, 330, 311, 294, 277, 262, 247
����������8us��	233, 220, 208, 196, 185, 175, 165, 155, 147, 138, 131, 123 
����������8us��	116, 110, 104, 98,  92,  87,  82,  78,  73,  69,  65,  62  */

#define BDo0 466
#define BDo	 233
#define BDo1 116

#define Bre0 415
#define Bre  208
#define Bre1 104

#define Bmi0 370
#define Bmi  185
#define Bmi1 92

#define Bfa0 349
#define Bfa  175
#define Bfa1 87

#define Bso0 311
#define Bso  155
#define Bso1 78

#define Bla0 277
#define Bla  138
#define Bla1 69

#define Bsi0  247
#define Bsi   123
#define Bsi1  62

 


#define B4XZ   1000	  //����ֹ����������ֻ�õ��˷���ֹ
#define B8XZ   65535	  //����ֹ����������ֻ�õ��˷���ֹ

#define STP  0x00	  //������






/***����£�����ʱֵ�궨�壬���455msһ��,��ʱ��0ÿ10msһ
    �Σ���ʱ��0������nΪ1ʱΪ10ms��������BΪ���*/

#define B0  182   //B0ȫ����    ���ٸ�ms 
#define	B0D 273   //D��˼Ϊ��������

#define B2  91		//��������
#define B2D 137

#define B4  46		//�ķ�����
#define B4D 68

#define B8  23		//�˷�����
#define B8D 34

#define B16   11		//ʮ��������
#define B16D  17

#define B32   6	// �����У�����������ʱֵΪ������1/4��������ʵ��ʱֵΪԭ����1/2�ٸ���
#define B32D  9    //���������������δ����

#define B8SYY 2    //8��������������ʱֵ


/*�а��£�����ʱֵ�궨�壬�а�682msһ��,��ʱ��0ÿ10msһ
    �Σ���ʱ��0������nΪ1ʱΪ10ms�������У�ZBΪ�а�*/
#define ZB0  273   //B0ȫ����
#define	ZB0D 409   //DΪ  ��������

#define ZB2  136
#define ZB2D 205

#define ZB4  68
#define ZB4D 102

#define ZB8  34
#define ZB8D 51

#define ZB16   17
#define ZB16D  26

#define ZB32   9// �����У�����������ʱֵΪ������1/4��������ʵ��ʱֵΪԭ����1/2�ٸ���
#define ZB32D  13    //���������������δ����

#define ZB8SYY 2    //8��������������ʱֵ   


/*�����£�����ʱֵ�궨�壬�а�682msһ��,��ʱ��0ÿ10msһ
    �Σ���ʱ��0������nΪ1ʱΪ10ms�������У�ZBΪ�а�*/
#define Z0  400   //B0ȫ����
#define	Z0D 600   //DΪ  ��������

#define Z2  200
#define Z2D 300

#define Z4  100
#define Z4D 150

#define Z8  50
#define Z8D 75

#define Z16   25
#define Z16D  37

#define Z32   12// �����У�����������ʱֵΪ������1/4��������ʵ��ʱֵΪԭ����1/2�ٸ���
#define Z32D  18    //���������������δ����

#define Z8SYY 2   //8��������������ʱֵ 
/*���ӵ����飬������Ű���ÿ��һС�ڣ�
Ԫ�ص�����˳��Ϊ��������, ʱֵ��������������, ʱֵ����......*/

unsigned int code music_Chunjie[] ={   

mi1,B8,mi1,B16,re1,B16,Do1,B4,mi1,B8,mi1,B16,re1,B16,
Do1,B4,mi1,B8,mi,B16,re1,B16,Do1,B8,so,B8,mi,B8,la,B8,
so,B8D,la,B16,so,B8,la,B8,so,B8D,la,B16,so,B8,la,B8,
so,B8,la,B8,so,B8,la,B8,so,B8,la,B8,so,B8,la,B8,
so,B16,la,B16,si,B16,la,B16,so,B16,la,B16,si,B16,la,B16,so,B16,la,B16,si,B16,la,B16,so,B16,la,B16,si,B16,la,B16,
so,B4,so,B4,so,B2,
so,B8,so,B16,la,B16,so,B8,so,B16,la,B16,
Do1,B8,Do1,B16,la,B16,Do1,B8,Do1,B16,re1,B16,
mi1,B8,mi1,B16,re1,B16,mi1,B8,mi1,B16,re1,B16,
mi1,B8,mi1,B16,re1,B16,Do1,B8,Do1,B16,la,B16,
so,B8,so,B16,la,B16,so,B8,so,B16,la,B16,
Do1,B8,Do1,B16,la,B16,Do1,B8,Do1,B16,re1,B16,
mi1,B8,mi1,B16,re1,B16,mi1,B8,mi1,B16,re1,B16,
mi1,B8,mi1,B16,re1,B16,Do1,B8,Do1,B16,la,B16,
so,B8,so,B16,la,B16,Do1,B8,Do1,B16,re,B16,
mi1,B8,mi1,B16,re,B16,Do1,B4,Do1,B4,mi,B4,Do1,B4,mi,B4,
Do1,B8D,la,B16,Do1,B8,la,B8,so,B8,Do1,B8,la,B8,so,B8,mi,B8,so,B8,re,B8,mi,B8,so,B8,la,B8,mi,B8,mi,B16,re,B16,Do,B4,mi1,B8,mi1,B16,re1,B16,Do1,B0,

Do1,B8D,mi1,B16,re1,B8,mi1,B8,so,B4D,Do1,B8,la,B8,so,B16,mi,B8,re,B16,mi,B16,so,B2,Do1,B8D,mi1,B16,re1,B8,mi1,B8,so,B4D,Do,B8,la,B8,so,B8,mi,B8,re,B8,Do,B2,  
Do1,B8D,mi1,B16,re1,B8,mi1,B8,so,B4D,Do1,B8,la,B8,so,B16,mi,B8,re,B16,mi,B16,so,B2,Do1,B8D,mi1,B16,re1,B8,mi1,B8,so,B4D,Do,B8,la,B8,so,B8,mi,B8,re,B8,Do,B2,  

la,B8,la,B8,so,B8,mi,B4,  
      la,B8,so,B8,mi,B4,
      la,B8,so,B8,mi,B4,
      la,B8,so,B8,la,B8,
so,B8,la,B8,so,B8,la,B8,
so1,B8,la1,B8,so1,B8,la1,B8,
so1,B8,la1,B8,so1,B8,la1,B8,
so1,B4,so1,B4,so1,B2D,            
0x00,
};   


unsigned int code music_Guyongzhe[] ={   
Bla,Z16, Bsi,Z16,  //����
BDo1,Z16, Bre1,Z16, Bsi,Z16, BDo1,Z16,  BDo1,Z8, BDo1,Z16, Bsi,Z16,   //�����߰��ﰮ��
BDo1,Z16, Bre1,Z16, Bsi,Z16, BDo1,Z16,  BDo1,Z8, BDo1,Z16, Bre1,Z16,  //�����ģ������
Bmi1,Z16, Bre1,Z16, Bmi1,Z16, Bre1,Z16, Bmi1,Z8, Bmi1,Z16, Bre1,Z16,  //���Ź���������
Bmi1,Z8, Bso1,Z8, Bmi1,Z8, Bla,Z16, Bsi,Z16,   //��һ��,����
BDo1,Z16, Bre1,Z16, Bsi,Z16, BDo1,Z16,  BDo1,Z8, BDo1,Z16, Bsi,Z16,   //���õ�����ȴ��
BDo1,Z16, Bre1,Z16, Bsi,Z16, BDo1,Z16,  BDo1,Z8, BDo1,Z16, Bre1,Z16,  //�����˵�ǽ����
Bmi1,Z16, Bre1,Z16, Bmi1,Z16, Bre1,Z16, Bmi1,Z8, Bmi1,Z16, Bre1,Z16,  //������ô��ȱ��
Bmi1,Z8, Bso1,Z8, Bmi1,Z8, Bso1,Z8,   //��һ��. ȥ
Bmi1,Z8D,Bso1,Z16,Bmi1,Z8D,Bso1,Z16, //��������
Bmi1,Z16,Bso1,Z16,Bla1,Z16,Bmi1,Z16, Bso1,Z8,Bso1,Z8,   //���ڵ��� ��ս
Bmi1,Z8D,Bso1,Z16,Bmi1,Z8D,Bso1,Z16, //��ս�� ��
Bmi1,Z16,Bso1,Z16,Bla1,Z16,Bmi1,Z16, Bso1,Z8,Bso1,Z8,   //�΢����,����
Bmi1,Z16,Bre1,Z16,Bre1,Z8, Bre1,Z8,BDo1,Z8,Bmi1,Z16, 	 //��ҹ�е���
Bmi1,Z16,Bre1,Z16,Bre1,Z8, Bre1,Z8,BDo1,Z8,BDo1,Z16,    //   ����ŭ��
Bla,Z2, B4XZ,Z4, B8XZ,Z8, Bso1,Z16, Bso1,Z16,			//˭˵
Bmi1,Z16, Bre1,Z16, Bre1,Z8, Bre1,Z8, BDo1,Z16, Bmi1,Z16,    //վ�ڹ����
Bmi1,Z16, Bre1,Z16, Bre1,Z8, Bre1,Z8, BDo1,Z16, BDo1,Z16,    //  ����Ӣ��

0x00,
};   

unsigned int code music_test[] ={   
Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, 
Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, 
Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, 
Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, Bla,Z16,Bsi,Z16, 

0x00,
};   

unsigned int code music_none[] = { 0x00, };



#endif
