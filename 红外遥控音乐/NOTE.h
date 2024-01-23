#ifndef __NOTE_H__
#define __NOTE_H__


/*********** 国际标准音A-la-440HZ(Do为261.6HZ), 按半音递增增长, 即增长倍率为2的1/12次方 *************/
/*     计算公式为440HZ*2^(i/12), 其中i为该音符与La音的标准Hash距离       */
/***************************    C大调音符频率    **********************************/
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So		So#	 La 	La#	 Si
                1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
低音频率（   ）	262  277  294  311  330  349  370  392  415  440  466  494
中音频率（   ）	523  554  587  622  659  698  740  784  831  880  932  988 
高音频率（   ）	1046 1109 1175 1245 1318 1397 1480 1568 1661 1760 1865 1976 
*/
/***************************    D大调音符频率    **********************************/
/*  	          Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So		So#	 La 	La#	 Si
                1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
低音频率（   ）	294  311  330  349  370  392  415  440  466  494  523  554
中音频率（   ）	587  622  659  698  740  784  831  880  932  988  1046 1109 
高音频率（   ）	1175 1245 1318 1397 1480 1568 1661 1760 1865 1976 2093 2217 
*/

/***************************    G大调音符频率    **********************************/
/*  	          Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So		So#	 La 	La#	 Si
                1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
低音频率（   ）	392  415  440  466  494  523  554  587  622  659  698  740
中音频率（   ）	784  831  880  932  988  1046 1109 1175 1245 1318 1397 1480
高音频率（   ）	1568 1661 1760 1865 1976 2093 2217 2349 2489 2637 2794 2960
*/

/***************************    B大调音符频率    **********************************/
/*  	          Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So		So#	 La 	La#	 Si
                1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
低音频率（   ）	494  523  554  587  622  659  698  740  784  831  880  932  
中音频率（   ）	988  1046 1109 1175 1245 1318 1397 1480 1568 1661 1760 1865 
高音频率（   ）	1976 2093 2217 2349 2489 2637 2794 2960 3136 3322 3520 3729
*/


/*************** C大调音阶宏定义	，0代表低音，1代表高音**********************************/
/***********   每个音符对应的音符常数m(当延时时间=8i+2  us时), 得到1/f= 0.5*(8*m+2)*0.000001*1.085 *********/										
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So	  So#	 La 	La#	 Si
								1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
低音常数（8us）	880, 831, 784, 740, 699, 660, 623, 588, 555, 523, 494, 466 
中音常数（8us）	440, 415, 392, 370, 349, 330, 311, 294, 277, 262, 247, 233 
高音常数（8us）	220, 208, 196, 185, 175, 165, 155, 147, 138, 131, 123, 116  */

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


/*************** D大调音阶宏定义	，0代表低音，1代表高音**********************************/									
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So	  So#	 La 	La#	 Si
								1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
低音常数（8us）	784, 740, 699, 660, 623, 588, 555, 523, 494, 466, 440, 415
中音常数（8us）	392, 370, 349, 330, 311, 294, 277, 262, 247, 233, 220, 208 
高音常数（8us）	196, 185, 175, 165, 155, 147, 138, 131, 123, 116, 110, 104  */

#define Do0 850	 //do为专用指令，因此改为大写D
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

/*************** G大调音阶宏定义	，0代表低音，1代表高音**********************************/									
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So	  So#	 La 	La#	 Si
								1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
低音常数（8us）	588, 555, 523, 494, 466, 440, 415, 392, 370, 349, 330, 311
中音常数（8us）	294, 277, 262, 247, 233, 220, 208, 196, 185, 175, 165, 155 
高音常数（8us）	147, 138, 131, 123, 116, 110, 104, 98,  92,  87,  82,  78  */

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

/*************** B大调音阶宏定义	，0代表低音，1代表高音**********************************/									
/*	            Do	 Do#	Re	 Re#	Mi	 Fa	  Fa#	 So	  So#	 La 	La#	 Si
								1    1#   2    2#   3    4    4#   5    5#   6    6#   7 
低音常数（8us）	466, 440, 415, 392, 370, 349, 330, 311, 294, 277, 262, 247
中音常数（8us）	233, 220, 208, 196, 185, 175, 165, 155, 147, 138, 131, 123 
高音常数（8us）	116, 110, 104, 98,  92,  87,  82,  78,  73,  69,  65,  62  */

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

 


#define B4XZ   1000	  //四休止符，本例中只用到八分休止
#define B8XZ   65535	  //八休止符，本例中只用到八分休止

#define STP  0x00	  //结束符






/***快板下，音符时值宏定义，快板455ms一拍,定时器0每10ms一
    次，定时器0函数中n为1时为10ms，本例中B为快板*/

#define B0  182   //B0全音符    多少个ms 
#define	B0D 273   //D意思为附点音符

#define B2  91		//二分音符
#define B2D 137

#define B4  46		//四分音符
#define B4D 68

#define B8  23		//八分音符
#define B8D 34

#define B16   11		//十六分音符
#define B16D  17

#define B32   6	// 本例中，定单倚音的时值为主音的1/4，则主音实际时值为原来的1/2再附点
#define B32D  9    //其余特殊节奏型暂未定义

#define B8SYY 2    //8分音符的三倚音时值


/*中板下，音符时值宏定义，中板682ms一拍,定时器0每10ms一
    次，定时器0函数中n为1时为10ms，本例中，ZB为中板*/
#define ZB0  273   //B0全音符
#define	ZB0D 409   //D为  附点音符

#define ZB2  136
#define ZB2D 205

#define ZB4  68
#define ZB4D 102

#define ZB8  34
#define ZB8D 51

#define ZB16   17
#define ZB16D  26

#define ZB32   9// 本例中，定单倚音的时值为主音的1/4，则主音实际时值为原来的1/2再附点
#define ZB32D  13    //其余特殊节奏型暂未定义

#define ZB8SYY 2    //8分音符的三倚音时值   


/*慢板下，音符时值宏定义，中板682ms一拍,定时器0每10ms一
    次，定时器0函数中n为1时为10ms，本例中，ZB为中板*/
#define Z0  400   //B0全音符
#define	Z0D 600   //D为  附点音符

#define Z2  200
#define Z2D 300

#define Z4  100
#define Z4D 150

#define Z8  50
#define Z8D 75

#define Z16   25
#define Z16D  37

#define Z32   12// 本例中，定单倚音的时值为主音的1/4，则主音实际时值为原来的1/2再附点
#define Z32D  18    //其余特殊节奏型暂未定义

#define Z8SYY 2   //8分音符的三倚音时值 
/*谱子的数组，下面的排版是每行一小节，
元素的排列顺序为音符参数, 时值参数，音符参数, 时值参数......*/

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
Bla,Z16, Bsi,Z16,  //爱你
BDo1,Z16, Bre1,Z16, Bsi,Z16, BDo1,Z16,  BDo1,Z8, BDo1,Z16, Bsi,Z16,   //孤身走暗巷爱你
BDo1,Z16, Bre1,Z16, Bsi,Z16, BDo1,Z16,  BDo1,Z8, BDo1,Z16, Bre1,Z16,  //不跪的模样爱你
Bmi1,Z16, Bre1,Z16, Bmi1,Z16, Bre1,Z16, Bmi1,Z8, Bmi1,Z16, Bre1,Z16,  //对峙过绝望不肯
Bmi1,Z8, Bso1,Z8, Bmi1,Z8, Bla,Z16, Bsi,Z16,   //哭一场,爱你
BDo1,Z16, Bre1,Z16, Bsi,Z16, BDo1,Z16,  BDo1,Z8, BDo1,Z16, Bsi,Z16,   //破烂的衣裳却敢
BDo1,Z16, Bre1,Z16, Bsi,Z16, BDo1,Z16,  BDo1,Z8, BDo1,Z16, Bre1,Z16,  //堵命运的墙爱你
Bmi1,Z16, Bre1,Z16, Bmi1,Z16, Bre1,Z16, Bmi1,Z8, Bmi1,Z16, Bre1,Z16,  //和我那么像缺口
Bmi1,Z8, Bso1,Z8, Bmi1,Z8, Bso1,Z8,   //都一样. 去
Bmi1,Z8D,Bso1,Z16,Bmi1,Z8D,Bso1,Z16, //吗配吗这
Bmi1,Z16,Bso1,Z16,Bla1,Z16,Bmi1,Z16, Bso1,Z8,Bso1,Z8,   //褴褛的披 风战
Bmi1,Z8D,Bso1,Z16,Bmi1,Z8D,Bso1,Z16, //吗战啊 以
Bmi1,Z16,Bso1,Z16,Bla1,Z16,Bmi1,Z16, Bso1,Z8,Bso1,Z8,   //最卑微的梦,致那
Bmi1,Z16,Bre1,Z16,Bre1,Z8, Bre1,Z8,BDo1,Z8,Bmi1,Z16, 	 //黑夜中的呜
Bmi1,Z16,Bre1,Z16,Bre1,Z8, Bre1,Z8,BDo1,Z8,BDo1,Z16,    //   咽与怒吼
Bla,Z2, B4XZ,Z4, B8XZ,Z8, Bso1,Z16, Bso1,Z16,			//谁说
Bmi1,Z16, Bre1,Z16, Bre1,Z8, Bre1,Z8, BDo1,Z16, Bmi1,Z16,    //站在光里的
Bmi1,Z16, Bre1,Z16, Bre1,Z8, Bre1,Z8, BDo1,Z16, BDo1,Z16,    //  才算英雄

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
