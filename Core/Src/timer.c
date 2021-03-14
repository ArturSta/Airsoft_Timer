#include "timer.h"
//--------------------------------------------------
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
//--------------------------------------------------
int runR = 0; //running timer for red team
int runG = 0; //running timer for green team
int runB = 0; //running timer for blue team
int runW = 0; //running timer for white team
int ButtonStateR = 0;
int ButtonStateG = 0;
int ButtonStateB = 0;
int ButtonStateW = 0;
int scoreR = 1;
int scoreG = 1;
int scoreB = 1;
int scoreW = 1;
//--------------------------------------------------
void timer_ini(void)
{
	lcd_init ();
	lcd2_init();
	lcd_send_string ("SVEIKI");
	HAL_Delay(1000);
	lcd_put_cur(1,0);
	lcd_send_string("AIRSOFTGAME");
	LEDR_ON();
	HAL_Delay(500);
	LEDR_OFF();
	LEDG_ON();
	HAL_Delay(500);
	LEDG_OFF();
	LEDB_ON();
	HAL_Delay(500);
	LEDG_ON();
	LEDR_ON();
	HAL_Delay(500);
	LEDR_OFF();
	LEDG_OFF();
	LEDB_OFF();
	lcd_clear ();
	lcd_put_cur(0,0);
	lcd_send_string("RED");
	lcd_put_cur(1,0);
	lcd_send_string("GREEN");
	lcd2_put_cur(0,0);
	lcd2_send_string("BLUE");
	lcd2_put_cur(1,0);
	lcd2_send_string("WHITE");
}
//--------------------------------------------------
void rst_red(void)
{
	if (LISTENR() == 0) // reseting red team scores
	  {
		  lcd_put_cur(0, 9);
		  lcd_send_string ("00");
		  lcd_put_cur(0, 12);
		  lcd_send_string ("0000");
		  scoreR = 0;
		  runR = 0;
	  }
}
//--------------------------------------------------
void rst_green(void)
{
	if (LISTENG() == 0)  // reseting green team scores
	  {
		  lcd_put_cur(1, 9);
		  lcd_send_string ("00");
		  lcd_put_cur(1, 12);
		  lcd_send_string ("0000");
		  scoreG = 0;
		  runG = 0;
	  }
}
//--------------------------------------------------
void rst_blue(void)
{
	if (LISTENB() == 0)  // reseting blue team scores
	  {
		  lcd2_put_cur(0, 9);
		  lcd2_send_string ("00");
		  lcd2_put_cur(0, 12);
		  lcd2_send_string ("0000");
		  scoreB = 0;
		  runB = 0;
	  }
}
//--------------------------------------------------
void rst_white(void)
{
	if (LISTENW() == 0)  // reseting white team scores
	  {
		  lcd2_put_cur(1, 9);
		  lcd2_send_string ("00");
		  lcd2_put_cur(1, 12);
		  lcd2_send_string ("0000");
		  scoreW = 0;
		  runW = 0;
	  }
}
//--------------------------------------------------
void timer_rst(void) // check all reset states
{
	rst_red();
	rst_green();
	rst_blue();
	rst_white();
}
//--------------------------------------------------
void red_team(void)	  // Code for RED Team
{
	  labelR:
	  LEDR_OFF();
	  HAL_Delay(500);
	  ButtonStateR = 0;
	  if (HAL_GPIO_ReadPin(RB_GPIO_PORT, RB_PIN) == 0 && ButtonStateR == 0)
	  {
		  LEDR_ON();
		  LIGHT();
		  ButtonStateR = 1;

		  for (runR; runR<=60; runR++) //time counting
		  {
			  char time[2];
			  itoa(runR, time, 10);
			  if (runR < 10)
			  {
				  lcd_put_cur(0,10);
			  }
			  if (runR>=10)
			  {
				  lcd_put_cur(0,9);
			  }
			  lcd_send_string(time);
			  HAL_Delay(1000);

			  if (runR == 60)  // score counting
			  {
				  runR = 0;
				  lcd_put_cur(0,9);
				  lcd_send_string("00");
				  lcd_put_cur(0,12);
				  lcd_send_string("0000");
				  char scoreRed[4];
				  itoa(scoreR, scoreRed, 10);
				  lcd_put_cur(0,15);
				  lcd_send_string(scoreRed);
				  if (scoreR < 10)
				  {
					  lcd_put_cur(0,15);
					  lcd_send_string(scoreRed);
				  }
				  if (scoreR >= 10 && scoreR < 100)
				  {
					  lcd_put_cur(0,14);
					  lcd_send_string(scoreRed);
				  }
				  if (scoreR >= 100 && scoreR < 1000)
				  {
					  lcd_put_cur(0,13);
					  lcd_send_string(scoreRed);
				  }
				  if (scoreR >= 1000 && scoreR <10000)
				  {
					  lcd_put_cur(0,12);
					  lcd_send_string(scoreRed);
				  }
				  scoreR++;
			  }

			  timer_rst();

			  if (HAL_GPIO_ReadPin(RB_GPIO_PORT, RB_PIN) == 0 && ButtonStateR == 1) //stop score counting
			  {
				  LIGHT();
				  goto labelR;
			  }
		  }
	  }
}
//--------------------------------------------------
void green_team(void)	  //Code for green team
{
	  labelG:
	  LEDG_OFF();
	  HAL_Delay(500);
	  ButtonStateG = 0;
	  if (HAL_GPIO_ReadPin(GB_GPIO_PORT, GB_PIN) == 0 && ButtonStateG == 0)
	  {
		  LEDG_ON();
		  LIGHT();
		  ButtonStateG = 1;

		  for (runG; runG<=60; runG++) //time counting
		  {
			  char time[2];
			  itoa(runG, time, 10);
			  if (runG < 10)
			  {
				  lcd_put_cur(1,10);
			  }
			  if (runG>=10)
			  {
				  lcd_put_cur(1,9);
			  }
			  lcd_send_string(time);
			  HAL_Delay(1000);

			  if (runG == 60)  // score counting
			  {
				  runG = 0;
				  lcd_put_cur(1,9);
				  lcd_send_string("00");
				  lcd_put_cur(1,12);
				  lcd_send_string("0000");
				  char scoreGreen[4];
				  itoa(scoreG, scoreGreen, 10);
				  lcd_put_cur(1,15);
				  lcd_send_string(scoreGreen);
				  if (scoreG < 10)
				  {
					  lcd_put_cur(1,15);
					  lcd_send_string(scoreGreen);
				  }
				  if (scoreG >= 10 && scoreG < 100)
				  {
					  lcd_put_cur(1,14);
					  lcd_send_string(scoreGreen);
				  }
				  if (scoreG >= 100 && scoreG < 1000)
				  {
					  lcd_put_cur(1,13);
					  lcd_send_string(scoreGreen);
				  }
				  if (scoreG >= 1000 && scoreG <10000)
				  {
					  lcd_put_cur(1,12);
					  lcd_send_string(scoreGreen);
				  }
				  scoreG++;
			  }

			  timer_rst();

			  if (HAL_GPIO_ReadPin(GB_GPIO_PORT, GB_PIN) == 0 && ButtonStateG == 1) //stop score counting
			  {
				  LIGHT();
				  goto labelG;
			  }
		  }
	  }
}
//--------------------------------------------------
void blue_team(void)	  //Code for blue team
{
	  labelB:
	  LEDB_OFF();
	  HAL_Delay(500);
	  ButtonStateB = 0;
	  if (HAL_GPIO_ReadPin(BB_GPIO_PORT, BB_PIN) == 0 && ButtonStateB == 0)
	  {
		  LEDB_ON();
		  LIGHT();
		  ButtonStateB = 1;

		  for (runB; runB<=60; runB++) //time counting
		  {
			  char time[2];
			  itoa(runB, time, 10);
			  if (runB < 10)
			  {
				  lcd2_put_cur(0,10);
			  }
			  if (runB>=10)
			  {
				  lcd2_put_cur(0,9);
			  }
			  lcd2_send_string(time);
			  HAL_Delay(1000);

			  if (runB == 60)  // score counting
			  {
				  runB = 0;
				  lcd2_put_cur(0,9);
				  lcd2_send_string("00");
				  lcd2_put_cur(0,12);
				  lcd2_send_string("0000");
				  char scoreBlue[4];
				  itoa(scoreB, scoreBlue, 10);
				  lcd2_put_cur(0,15);
				  lcd2_send_string(scoreBlue);
				  if (scoreB < 10)
				  {
					  lcd2_put_cur(0,15);
					  lcd2_send_string(scoreBlue);
				  }
				  if (scoreB >= 10 && scoreB < 100)
				  {
					  lcd2_put_cur(0,14);
					  lcd2_send_string(scoreBlue);
				  }
				  if (scoreB >= 100 && scoreB < 1000)
				  {
					  lcd2_put_cur(0,13);
					  lcd2_send_string(scoreBlue);
				  }
				  if (scoreB >= 1000 && scoreB <10000)
				  {
					  lcd2_put_cur(0,12);
					  lcd2_send_string(scoreBlue);
				  }
				  scoreB++;
			  }

			  timer_rst();

			  if (HAL_GPIO_ReadPin(BB_GPIO_PORT, BB_PIN) == 0 && ButtonStateB == 1) //stop score counting
			  {
				  LIGHT();
				  goto labelB;
			  }
		  }
	  }
}
//--------------------------------------------------
void white_team(void)	  //Code for white team
{
	  labelW:
	  LEDR_OFF();
	  LEDG_OFF();
	  LEDB_OFF();
	  HAL_Delay(500);
	  ButtonStateW = 0;
	  if (HAL_GPIO_ReadPin(WB_GPIO_PORT, WB_PIN) == 0 && ButtonStateW == 0)
	  {
		  LEDR_ON();
		  LEDG_ON();
		  LEDB_ON();
		  LIGHT();
		  ButtonStateW = 1;

		  for (runW; runW<=60; runW++) //time counting
		  {
			  char time[2];
			  itoa(runW, time, 10);
			  if (runW < 10)
			  {
				  lcd2_put_cur(1,10);
			  }
			  if (runW>=10)
			  {
				  lcd2_put_cur(1,9);
			  }
			  lcd2_send_string(time);
			  HAL_Delay(1000);

			  if (runW == 60)  // score counting
			  {
				  runW = 0;
				  lcd2_put_cur(1,9);
				  lcd2_send_string("00");
				  lcd2_put_cur(1,12);
				  lcd2_send_string("0000");
				  char scoreWhite[4];
				  itoa(scoreW, scoreWhite, 10);
				  lcd2_put_cur(1,15);
				  lcd2_send_string(scoreWhite);
				  if (scoreW < 10)
				  {
					  lcd2_put_cur(1,15);
					  lcd2_send_string(scoreWhite);
				  }
				  if (scoreW >= 10 && scoreW < 100)
				  {
					  lcd2_put_cur(1,14);
					  lcd2_send_string(scoreWhite);
				  }
				  if (scoreW >= 100 && scoreW < 1000)
				  {
					  lcd2_put_cur(1,13);
					  lcd2_send_string(scoreWhite);
				  }
				  if (scoreW >= 1000 && scoreW <10000)
				  {
					  lcd2_put_cur(1,12);
					  lcd2_send_string(scoreWhite);
				  }
				  scoreW++;
			  }

			  timer_rst();

			  if (HAL_GPIO_ReadPin(WB_GPIO_PORT, WB_PIN) == 0 && ButtonStateW == 1) //stop score counting
			  {
				  LIGHT();
				  goto labelW;
			  }
		  }
	  }
}
//--------------------------------------------------
