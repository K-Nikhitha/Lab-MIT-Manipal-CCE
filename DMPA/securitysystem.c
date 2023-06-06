#include<lpc17xx.h>
#include<stdio.h>
#include "ocf_lpc176x_lib.h" //Contains initUART0(),initTimer0(),putc()
#include "ocf_lpc176x_lib.c"

//LCD
#define RS_CTRL 0x08000000 //P0.27
#define EN_CTRL 0x10000000 //P0.28
#define DT_CTRL 0x07800000 //P0.23 to P0.26 data lines

//HC-SR04
#define TRIG (1<<15) //P0.15
#define ECHO (1<<16) //P0.16

//Buzzer
#define BUZZ (1<<11) //P0.11

void lcd_init(void);
void wr_cn(void);
void clr_disp(void);
void delay_lcd(unsigned int);
void lcd_com(void);
void wr_dn(void);
void lcd_data(void);
void clear_ports(void);
void lcd_puts(unsigned char *);
void print_dist(float f);
void buzz(int pc);
extern unsigned long int temp1,temp2;
unsigned long int temp1=0, temp2=0;
float threshold = 50;

int main(void)
{
  SystemInit();         //StartupCode
  SystemCoreClockUpdate();
  lcd_init();
  temp1=0x80;
  lcd_com();

  initUART0();    //initialise UART0
  initTimer0();   //Timer for delay functions
  int echoTime = 0;
  float distance = 0;
  int delay = 10;
  int buzz_delay = 150;
  int i = 1;
  int pc = 1;
  LPC_PINCON->PINSEL0&=0xFF3FFFFF;
  LPC_GPIO0->FIODIR |= 0x00000800;  //Buzzer Output P0.11
  LPC_GPIO0->FIODIR |=TRIG;         //Trigger output
  LPC_GPIO0->FIODIR &= ~(ECHO);     //ECHO input
  LPC_GPIO0->FIOCLR |= TRIG;

  while (1)
  {
    LPC_GPIO0->FIOPIN |= TRIG;
    delayUS(delay);
    LPC_GPIO0->FIOCLR |= TRIG;

    while(!(LPC_GPIO0->FIOPIN & ECHO)); //Wait fo High on ECHO
    startTimer0();      //Start Counting
    while(LPC_GPIO0->FIOPIN & ECHO); //Wait for Low on ECHO
    echoTime = stopTimer0();    //Stop counting and save value in echoTime
    distance = (0.0343*echoTime)/2; //Calculate distance
    print_dist(distance);
    printf("Distance = %0.2fcm\n",distance);

    if(distance<threshold)
    {
      float diff_ratio = (threshold-distance)/threshold;
      if(diff_ratio<0.25)
      {
        pc = 1;
        i=1;
        buzz_delay = 150;
      }
      else if(diff_ratio<0.50)
      {
        pc = 2;
        i=2;
        buzz_delay = 100;
      }
      else if(diff_ratio<0.75)
      {
        pc = 3;
        i=3;
        buzz_delay = 75;
      }
      else
      {
        pc = 5;
        i=4;
        buzz_delay = 50;
      }
      LPC_GPIO0->FIOSET=0x00000800;
      for(int k=0;k<i;k++)
      {
        LPC_GPIO0->FIOSET = 0x00000800;
        delayMS(buzz_delay);
        LPC_GPIO0->FIOCLR = 0x00000800;
        delayMS(buzz_delay);
      }
      buzz(pc);
    }
    delayMS(500);
    LPC_GPIO0->FIOCLR = 0x00000800;
  }
}


void print_dist(float f)
{
  unsigned char msg[11]={""};

  sprintf(msg,"%g",f);
  temp1 = 0x80;
  lcd_com();
  delay_lcd(400000);
  lcd_puts(&msg[0])
}
void lcd_init()
{
  LPC_PINCON->PINSEL3 &= 0xFC003FFF;
  //Setting the directions as output */
  LPC_GPIO0->FIODIR |= DT_CTRL;
  LPC_GPIO0->FIODIR |= RS_CTRL;
  LPC_GPIO0->FIODIR |= EN_CTRL;

  clear_ports();
  delay_lcd(3200);
  temp2 = (0x30<<19);
  wr_cn();
  delay_lcd(30000);
  temp2 = (0x30<<19);
  wr_cn();
  delay_lcd(30000);
  temp2 = (0x30<<19);
  wr_cn();
  delay_lcd(30000);
  temp2 = (0x20<<19);
  wr_cn();
  delay_lcd(30000);
  temp1 = 0x28;
  lcd_com();
  delay_lcd(30000);
  temp1 = 0x0c;
  lcd_com();
  delay_lcd(10000);
  temp1 = 0x06;
  lcd_com();
  delay_lcd(10000);
  temp1 = 0x01;
  lcd_com();
  delay_lcd(10000);
  temp1 = 0x80;
  lcd_com();
  delay_lcd(10000);
  return;
}

void lcd_com(void)
{
  temp2 = temp1 & 0xf0;//move data (26-8+1) times : 26 - HN
  //place, 4 - Bits
  temp2 = temp2 << 19; //data lines from 23 to 26
  wr_cn();
  temp2 = temp1 & 0x0f; //26-4+1
  temp2 = temp2 << 23;
  wr_cn();
  delay_lcd(100000);
  return;
}

void wr_cn(void) //write command reg
{
  clear_ports();
  LPC_GPIO0->FIOPIN = temp2; // Assign the value to the data
  //lines
  LPC_GPIO0->FIOCLR = RS_CTRL; // clear bit RS
  LPC_GPIO0->FIOSET = EN_CTRL; // EN=1
  delay_lcd(25);
  LPC_GPIO0->FIOCLR = EN_CTRL; // EN =0
  return;
}

void lcd_data(void)
{
  temp2 = temp1 & 0xf0;
  temp2 = temp2 << 19;
  wr_dn();
  temp2= temp1 & 0x0f;
  temp2= temp2 << 23;
  wr_dn();
  delay_lcd(100000);
  return;
}

void wr_dn(void)
{
  clear_ports();
  LPC_GPIO0->FIOPIN = temp2; // Assign the value to the
  //data lines
  LPC_GPIO0->FIOSET = RS_CTRL; // set bit RS
  LPC_GPIO0->FIOSET = EN_CTRL; // EN=1
  delay_lcd(100000);
  LPC_GPIO0->FIOCLR = EN_CTRL; // EN =0
  return;
}

void delay_lcd(unsigned int r1)
{
  unsigned int r;
  for(r=0;r<r1;r++);
  return;
}

void clr_disp(void)
{
  temp1 = 0x01;
  lcd_com();
  delay_lcd(100000);
  return;
}

void clear_ports(void)
{
  /* Clearing the lines at power on */
  LPC_GPIO0->FIOCLR = DT_CTRL; //Clearing data lines
  LPC_GPIO0->FIOCLR = RS_CTRL; //Clearing RS line
  LPC_GPIO0->FIOCLR = EN_CTRL; //Clearing Enable line
  return;
}

void lcd_puts(unsigned char *buf1)
{
  unsigned int i=0;
  while(buf1[i]!='\0')
  {
    temp1 = buf1[i];
    lcd_data();
    i++;
    if(i==16)
    {
      temp1 = 0xc0;
      lcd_com();
    }
  }
  return;
}

void buzz(int pc) {
    for (int j = 0; j < pc; j++) {
        LPC_GPIO0->FIOSET = BUZZ;    // Set the buzzer pin high
        delayMS(100);                // Delay for the desired pulse duration
        LPC_GPIO0->FIOCLR = BUZZ;    // Set the buzzer pin low
        delayMS(100);                // Delay between pulses
    }
}
