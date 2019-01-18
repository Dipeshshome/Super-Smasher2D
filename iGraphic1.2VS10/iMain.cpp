
#include<iostream>
# include "iGraphics.h"
#include "bitmap_loader.h"


  int  XCord=300;
  int YCord=200;
   int timer1;
   int point;
   
  int  direction =1;
  int direction1 =1;
  int dx1=83;
  int dy1=113;
  int dx2=83;
  int dy2=113;
  int dx3=50;
  int dy3=15;
  int hunter=0;
  int Length = 0;
  
  int page = 1;
  int button = 0;
  int mainMenu = 0;
  int playeLife=3;
  int enemyMiss=0;

  
 
  
  int flag=0;

   int Enemy_Speed=7;
 //int Enemy_Speed2=60;
 //int Enemy_Speed3=70;
 //int Enemy_Speed4=80;


  int EnemyX=1300;
  int EnemyY=50;
  int Enemy2X=1600;
  int Enemy2Y=300;

  int Enemy4X=-100;
  int Enemy4Y=80;
  int Enemy5X=-300;
  int Enemy5Y=250;

void mainPage();
void gameover();





  int bulletTimer1 = 0;
  

  int bulletCount = 0;
  
 
  

int pic1=-400,pic2=0,pic3=980,pic4=1900;


void Enemy()
{

	EnemyX-=Enemy_Speed;

	if(EnemyX==0)
	{
		enemyMiss++;
		EnemyX=1300;
   EnemyY=rand() %420;
	}
}
void Enemy2()
{

	Enemy2X-=Enemy_Speed;

	if(Enemy2X==0)
	{
		enemyMiss++;
        Enemy2X=1300;
        Enemy2Y=rand() %420+50;

	}
}

void Enemy4()
{

	Enemy4X+=Enemy_Speed;

	if(Enemy4X==1300)
	{
		enemyMiss++;
		Enemy4X=0;
   Enemy4Y=rand() %350;
	}
}
void Enemy5()
{

	Enemy5X+=Enemy_Speed;

	if(Enemy5X==1300)
	{
		enemyMiss++;
		Enemy5X=-200;
   Enemy5Y=rand() %350+50;
	}
}











struct Bullet 
{
	int x,y,x1,y1;
	bool Shot;             // controls if bullet is visible or not
}bullet[100];





void BulletShot()              
{
	
		for(int i = 0 ; i <=bulletCount ; i++)
	{
		if(hunter==0){
		
		if(bullet[i].Shot)
			bullet[i].x += 20;

		if(bullet[i].x >= 1300)
			bullet[i].Shot = false;
	}
		}
	
		

for(int i = 0 ; i <=bulletCount ; i++){
if(hunter==1)
		{

			if(bullet[i].Shot)
			bullet[i].x1 -= 20;

		if(bullet[i].x1 <= 0)
			bullet[i].Shot = false;
	}

	}
}

struct highScore
{
	char name[20];
	int score;

}player, Saved[5] , temp , temp1;

int PlayerNumber = 0;
FILE *fp;

bool NewHighScore = false;
bool NameInputTaken = false;
bool ScoreOnceChecked = true;
int score = 0;
//int i = 0;

char scorePrint[5];
char scorePrint1[5];
char scorePrint2[5];
char scorePrint3[5];
char scorePrint4[5];

int scoreTemp = 0;
int scoreTemp2 = 0;
int scoreTemp3 = 0;
int scoreDigit = 0;
int factor = 1;
//char scoreArray[100];
//char scoreArray2[100];
//char scr[100]; // debug
int scoreArray3[5] = {0,0,0,0,0};


void ScoreCheck()   // Checking the scores !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! PROBLEM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	if(ScoreOnceChecked)
		{
			player.score = score;
			
		for(int j = 0; j<5 ;j++)
		{
			if(player.score > Saved[j].score)
			{
				for(int k = 4 ; k>j ; k--)
				{
					Saved[k] = Saved[k-1];
				}
				Saved[j] = player;
				PlayerNumber = j;
				NewHighScore = true;
				break;
			}
		}
		
		scoreTemp = score;
		scoreTemp2 = scoreTemp3 = score;
		
		while(scoreTemp > 0)
		{
			scoreTemp = scoreTemp / 10;
			scoreDigit++;
		}

		while( scoreTemp2 !=0)
		{
			scoreTemp2 /= 10;
			factor = factor * 10;
		}
		int j = 0;
		while(factor > 1)
		{
			factor = factor/10;
			scoreArray3[j] = scoreTemp3 / factor ;
			scoreTemp3 = scoreTemp3 % factor;
			j++;
		}

		ScoreOnceChecked = false;
		page = 5;
	}
}

	
	


	








/* 
	function iDraw() is called again and again by the system.
*/





void mainPage()
{
	iShowBMP(0,0,"mainpageD.bmp");


	iShowBMP(230,500,"startpageD.bmp");
	if(button == 1)
		iShowBMP(230,500,"startpageD1.bmp");
		iShowBMP(150,400,"instructionsD.bmp");
	if(button == 2)
		iShowBMP(150,400,"instructionsD1.bmp");

	iShowBMP(220,300,"HighScoresD1.bmp");
	if(button == 3)
		iShowBMP(220,300,"HighScoresD.bmp");
	
	iShowBMP(150,200,"ExitD.bmp");
	if(button == 4)
		iShowBMP(150,200,"ExitD1.bmp");
	iShowBMP(270,100,"aboutD.bmp");
	if(button == 5)
		iShowBMP(270,100,"aboutD1.bmp");
}


void gameover()
{
 iShowBMP(0,0,"Gameover.bmp");
 if(mainMenu == 0)
			iShowBMP(1100,20,"backD1.bmp");
		if(mainMenu == 1 )
			iShowBMP(1100,20,"backD.bmp");

		if(scoreDigit == 2)
	{
		


		if(scoreArray3[0] == 1)	
			iShowBMP(175,573,"d1.bmp");
		else if(scoreArray3[0] == 2)
			iShowBMP(175,573,"d2.bmp");
		
		else if(scoreArray3[0] == 3)	
			iShowBMP(175,573,"d3.bmp");
		
		else if(scoreArray3[0] == 4)	
			iShowBMP(175,573,"d4.bmp");
		
		  if(scoreArray3[0] == 5)	
			 iShowBMP(175,573,"d5.bmp");
		
		else if(scoreArray3[0] == 6)	
			iShowBMP(175,573,"d6.bmp");
		
		else if(scoreArray3[0] == 7)	
			iShowBMP(175,573,"d7.bmp");
		
		else if(scoreArray3[0] == 8)	
			iShowBMP(175,573,"d8.bmp");
		
		else if(scoreArray3[0] == 9)	
			iShowBMP(175,573,"d9.bmp");
		
		iShowBMP(210,573,"d0.bmp");
		
	}

	else if( scoreDigit == 3)
	{
		


		if(scoreArray3[0] == 1)	
			iShowBMP(140,573,"d1.bmp");
		else if(scoreArray3[0] == 2)	
			iShowBMP(140,573,"d2.bmp");
		else if(scoreArray3[0] == 3)	
			iShowBMP(140,573,"d3.bmp");
		else if(scoreArray3[0] == 4)	
			iShowBMP(140,573,"d4.bmp");
		else if(scoreArray3[0] == 5)	
			iShowBMP(140,573,"d5.bmp");
		else if(scoreArray3[0] == 6)	
			iShowBMP(140,573,"d6.bmp");
		else if(scoreArray3[0] == 7)	
			iShowBMP(140,573,"d7.bmp");
		else if(scoreArray3[0] == 8)	
			iShowBMP(140,573,"d8.bmp");
		else if(scoreArray3[0] == 9)	
			iShowBMP(140,573,"d9.bmp");
	
		if(scoreArray3[1] == 0)	
			iShowBMP(175,573,"d0.bmp");
		else if(scoreArray3[1] == 1)	
			iShowBMP(175,573,"d1.bmp");
		else if(scoreArray3[1] == 2)	
			iShowBMP(175,573,"d2.bmp");
		else if(scoreArray3[1] == 3)	
			iShowBMP(175,573,"d3.bmp");
		else if(scoreArray3[1] == 4)	
			iShowBMP(175,573,"d4.bmp");
		else if(scoreArray3[1] == 5)	
			iShowBMP(175,573,"d5.bmp");
		else if(scoreArray3[1] == 6)	
			iShowBMP(175,573,"d6.bmp");
		else if(scoreArray3[1] == 7)	
			iShowBMP(175,573,"d7.bmp");
		else if(scoreArray3[1] == 8)	
			iShowBMP(175,573,"d8.bmp");
		else if(scoreArray3[1] == 9)	
			iShowBMP(175,573,"d9.bmp");
	
		iShowBMP(210,573,"d0.bmp");
		

	}

else
	{
		iShowBMP(175,573,"d0.bmp");
		iShowBMP(210,573,"d0.bmp");
	}




}
	



void iDraw()
{

	
	iClear();
   if(page == 1)
		mainPage();

 if (page ==2 )   // new game
	{
	
		

		iShowBMPAlternative(pic1, pic2, "background1.bmp");

	iShowBMPAlternative(pic3, pic2, "background1.bmp");

	iShowBMPAlternative(pic4, pic2, "background1.bmp");
	iShowBMP2(1100,680,"xcores.bmp",255);
	iShowBMP(1170,680,"scoreback.bmp");
	iShowBMP2(300,680,"enemylife.bmp",255);
	iShowBMP(370,680,"scoreback.bmp");

	if(hunter == 0){
		iShowBMP2(XCord,YCord,"Shooter.bmp",255);
	}
	if(hunter ==1){
		iShowBMP2(XCord,YCord,"Shooter1.bmp",255);
	}

	
	iShowBMP2(EnemyX,EnemyY,"enemy.bmp",255);
	

	
	
	
	iShowBMP2(Enemy2X,Enemy2Y,"enemy.bmp",255);
	iShowBMP2(Enemy4X,Enemy4Y,"enemy1.bmp",255);
	iShowBMP2(Enemy5X,Enemy5Y,"enemy1.bmp",255);
	
	iSetTimer(10,Enemy);
	iSetTimer(20,Enemy2);
	iSetTimer(25,Enemy4);
	iSetTimer(15,Enemy5);

	for(int i = 0; i < bulletCount ; i++){

		if(bullet[i].Shot == true && hunter == 0)
		
			
			iShowBMP2(bullet[i].x,bullet[i].y,"bullet.bmp",255);}



	for(int i = 0; i < bulletCount ; i++){

		if(bullet[i].Shot == true && hunter == 1)
		
			
		iShowBMP2(bullet[i].x1,bullet[i].y1,"bullet1.bmp",255);}
	

 

	if( (XCord >= EnemyX && XCord <= EnemyX+8)&&(YCord >= EnemyY && YCord <= (EnemyY+113)))
	{

		playeLife--;
		
		
	}
	else if( (XCord >= Enemy2X && XCord <= Enemy2X+8)&&(YCord+113 >= Enemy2Y && YCord <= (Enemy2Y+113)))
		{
		playeLife--;
		
		
	}
	else if((XCord >= Enemy4X && XCord <= Enemy4X+8)&&(YCord >= Enemy4Y && YCord <= (EnemyY+113)))
		{
		playeLife--;
		
		
	    }
	 else if((XCord >= Enemy5X && XCord <= Enemy5X+8)&&(YCord >= Enemy5Y && YCord <= (Enemy5Y+113)))
		{
		playeLife--;
		
	    }

	
	

	 if(EnemyX<-100||Enemy2X<-100||Enemy5X>1310||Enemy4X>1410)
	 {
	  enemyMiss++;
	 }
	  if(enemyMiss==3 )
	  {
		  
		ScoreCheck();
		page=5;
	  }
	 

	  if(playeLife== 0)
	{
		ScoreCheck();
		page=5;
	}



	
	 char secondsString[10];
         _itoa(score,secondsString,10);

		iText(1190,690,secondsString,GLUT_BITMAP_TIMES_ROMAN_24);
		 _itoa(enemyMiss,secondsString,10);
		 iText(400,690,secondsString,GLUT_BITMAP_TIMES_ROMAN_24);
		 _itoa(playeLife,secondsString,10);
		iText(100,690,secondsString,GLUT_BITMAP_TIMES_ROMAN_24);
		//iText(15, 730 , scoreArray2 ,GLUT_BITMAP_TIMES_ROMAN_24);
		//sprintf(scoreArray2,"Score : %d",score);
}


 if (page==4){
	 iShowBMP(0,0,"highscorePage.bmp");

	 if(mainMenu == 0)
			iShowBMP(1100,20,"backD1.bmp");
		if(mainMenu == 1 )
			iShowBMP(1100,20,"backD.bmp");

		iSetColor(255,0,0);
		iText(195,100, Saved[4].name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1070,90, scorePrint4 , GLUT_BITMAP_TIMES_ROMAN_24);
	   // sprintf(scorePrint4 , "%d" , Saved[4].score);

		iSetColor(255,0,0);
		iText(195,180, Saved[3].name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1070,170, scorePrint3 , GLUT_BITMAP_TIMES_ROMAN_24);	
			sprintf(scorePrint3 , "%d" , Saved[3].score);

		iSetColor(255,0,0);
		iText(195,260, Saved[2].name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1070,250, scorePrint2 , GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(scorePrint2 , "%d" , Saved[2].score);
		
		iSetColor(255,0,0);
		iText(195,340, Saved[1].name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1070,330, scorePrint1 , GLUT_BITMAP_TIMES_ROMAN_24);
	    sprintf(scorePrint1 , "%d" , Saved[1].score);
		
		iSetColor(255,0,0);
		iText(195,400, Saved[0].name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1070,390, scorePrint , GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(scorePrint , "%d" , Saved[0].score);
 
 }

  if(page==3){
	iShowBMP(0,0,"instructionPage.bmp");
	if(mainMenu == 0)
			iShowBMP(1100,20,"backD1.bmp");
		if(mainMenu == 1 )
			iShowBMP(1100,20,"backD.bmp");
	}
		



 if(page==5)
	 gameover();

 if(page == 6)
	{
		
		iShowBMP(0,0,"highscorePage.bmp");
		iSetColor(255,0,0);
		iText(165,365, player.name , GLUT_BITMAP_TIMES_ROMAN_24);

	}





/* if(page==7){
	iShowBMP(20,0,"aboutpageD.bmp");
	if(mainMenu == 0)
			iShowBMP(1100,20,"backD1.bmp");
		if(mainMenu == 1 )
			iShowBMP(1100,20,"backD.bmp");
	}
	*/
  


 

  
 

 }

 
 



	
	

 
	



/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	XCord=mx;
	YCord=my;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}
/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	
	//place your code here
	
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/
 
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)

{
if(page == 1)
	{
		if(key == '\r' )
		
		{
			if(button == 1)
			page = 2;
		    else if(button == 2)
				page = 3;
			else if (button == 3)
				page=4;
			
			else if(button == 4)
				exit(0);
			else if(button==5)
				page=7;
		
		}
	}
	
   if(page == 2)
	{

		if (key == 'z')
	{
		if(hunter==0){
		if(bulletCount < 100)
			bulletCount++;
		else if (bulletCount == 100)
			bulletCount = 0;

		bullet[bulletCount-1].Shot = true;
		bullet[bulletCount-1].y = YCord + 105;
		bullet[bulletCount-1].x = XCord +100;
	}
		if(hunter==1){
		if(bulletCount < 100)
			bulletCount++;
		else if (bulletCount == 100)
			bulletCount = 0;

		bullet[bulletCount-1].Shot = true;
		bullet[bulletCount-1].y1 = YCord + 105;
		bullet[bulletCount-1].x1 = XCord - 20;
	}


	
	 }
		
		if(key=='q'){
		page=1;
		}
	 }

	else if(page == 3 || page == 7||page==4)
	{
		if(mainMenu == 1)
			if(key == '\r')
			{
				page = 1;
				mainMenu = 0;
		
			}
	}
	else if(page == 5)
	{
		if(key == '\r')
		{
			if(NewHighScore == true)
			{
				page = 6;        // Name Input Page
			}
			else
				page = 4;       // Normal High SCore page
		}
	}

	else if(page == 6)
	{
			if(key == '\r')
			{
				for(int j = 0; player.name[j] != NULL ; j++)
				{
					Saved[PlayerNumber].name[j] = player.name[j];
				}
				
				fp = fopen("High Scores.txt" , "w");
				
				for(int j = 0 ; j < 5 ; j++)
				{
					fputs(Saved[j].name , fp);
					fprintf(fp, " %d\n", Saved[j].score);
				}
				for (int j = 0; j < Length; j++)
				{
					player.name[j] = 0;
					Length = 0;
				}

				page = 4;
			}
			else
				{
					player.name[Length] = key;
					Length++;
					
				}
	}
	
	
	

}
	

	//place your codes for other keys here
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{
	
	//if ( page == 2 )

		if(key == GLUT_KEY_DOWN)
		{
			button++;
			page ==2;
			
		}
		if(key == GLUT_KEY_UP)
		{
			button--;
			page ==2;
		}
	
	
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_UP)
	{
		YCord+=20;	
	}
	if(key == GLUT_KEY_DOWN)
	{
		YCord-=20;	
	}
	if(key == GLUT_KEY_LEFT)
	{

		XCord-=20;
		hunter =1;
		pic1+=40;
	    pic3+=40;
		pic4+=40;
	}


		
		
	if(key == GLUT_KEY_RIGHT)
	{
		 
		XCord+=20;
        hunter =0;
		pic1-=40;
	    pic3-=40;
		pic4-=40;
		
		
	}

	if(page == 4 || page == 5|| page == 3||page==7)
	{
		if(key == GLUT_KEY_DOWN)
		{
			mainMenu--;
			
			if (mainMenu == -1)
				mainMenu = 1;
		}
		if(key == GLUT_KEY_UP)
		{
			mainMenu++;
			
			if (mainMenu == 2)
				mainMenu = 0;
		}
	}
     //place your codes for other keys here
}


//




void CallSetTimer2()
{
		
	for(int i = 0; i < bulletCount ; i++){
		if(bullet[i].Shot == true&&hunter==0){



		if( (bullet[i].x >= EnemyX && bullet[i].x <= EnemyX+83)&&(bullet[i].y >= EnemyY && bullet[i].y <= (EnemyY+113)))
								
								{
									    EnemyX=false;
									    bullet[i].x=1800;
										score+=10;
										EnemyX=1500;
										EnemyY=rand() %420;
		                        }

		

		if( (bullet[i].x >= Enemy2X && bullet[i].x <= Enemy2X+83)&&(bullet[i].y >= Enemy2Y && bullet[i].y <= (Enemy2Y+113)))
								
							   {
								        Enemy2X=false;
								        bullet[i].x=1800;
										score+=10;
									    Enemy2X=1500;
										Enemy2Y=rand() %420+50;
		                        } 
		
	
	
}
	}
		
	for(int i = 0; i < bulletCount ; i++){
		if(bullet[i].Shot == true&&hunter==1){



		if ((bullet[i].x1 >= Enemy4X && bullet[i].x1 <= Enemy4X+83)&& (bullet[i].y1 >= Enemy4Y && bullet[i].y1 <= (Enemy4Y+113)))
								{
									    Enemy4X=false;
									    bullet[i].x1=-300;
										score+=10;
									    Enemy4X=-200;
										Enemy4Y=rand() %350;}

		
		if ((bullet[i].x1 >= Enemy5X && bullet[i].x1 <= Enemy5X+83)&&(bullet[i].y1>= Enemy5Y && bullet[i].y1 <= (Enemy5Y+113)))
								
										{Enemy5X=false;
									    bullet[i].x1=-500;
										score+=10;
									    Enemy5X=-100;
										Enemy5Y=rand() %350+50;}

		}
		}
	
		
	

	
}		

int main()
{
	//place your own initialization codes here. 
	bulletTimer1 = iSetTimer(15,BulletShot);
	timer1=iSetTimer(4,CallSetTimer2);

	fp = fopen("High Scores.txt", "a+" );
	int i=0;

	while (fscanf(fp, "%s %d", Saved[i].name, &Saved[i].score) != EOF)
		i++;
	fclose(fp);

	for(int j = 0; j<4 ; j++)
		for(int k = j+1 ; k < 5 ; k++)
			if(Saved[j].score < Saved[k].score)
			{
				temp = Saved[j];
				Saved[j] = Saved[k];
				Saved[k] = temp;
			
			}
	

	//iResumeTimer(bulletTimer1);
	//iResumeTimer(bulletTimer2);
	//timer1=iSetTimer(17,CallSetTimer);
	//timer2=iSetTimer(3,CallSetTimer1);
	//timer3=iSetTimer(1,CallSetTimer1);
	//timer4=iSetTimer(1,CallSetTimer3);
	//timer5=iSetTimer(1,CallSetTimer4);


	iInitialize(1380, 720, "demooo");
	return 0;
}	