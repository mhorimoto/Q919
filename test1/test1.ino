/*******
 *
 * Q919 test1
 * このプログラムは、リードスイッチのどれかがMakeしたことを
 * 検知してどのリードスイッチがMakeしたかを検出するだけの
 * プログラムである
 * 回転周期や回転数の積算などは考えてプログラムに
 * 反映するといいかもしれない。
 *
 * Author: 堀本　正文
 * Create: 19th May 2023
 *
 ********/

#define  TRIG   2  //  TRIGGER pin
#define  WSW1   6  //  Wheel switch 1
#define  WSW2   7  //  Wheel switch 2
#define  WSW3   8  //  Wheel switch 3
#define  WSW4   9  //  Wheel switch 4

volatile byte state = 0;

void setup(void) {
  pinMode(TRIG,INPUT_PULLUP);
  pinMode(WSW1,INPUT_PULLUP);
  pinMode(WSW2,INPUT_PULLUP);
  pinMode(WSW3,INPUT_PULLUP);
  pinMode(WSW4,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(TRIG),read_sw,FALLING);  
}

void loop(void) {
}

void read_sw(void) {
  if (digitalRead(WSW1)==LOW) state = 1;
  if (digitalRead(WSW2)==LOW) state = 2;
  if (digitalRead(WSW3)==LOW) state = 4;
  if (digitalRead(WSW4)==LOW) state = 8;
}
