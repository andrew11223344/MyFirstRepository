#include <iarduino_OLED.h>                                 // Подключаем библиотеку iarduino_OLED.
int KeyOutPin = 4;                  //Задействувем с 4-го по 8-й пины платы Arduino Nano
int KeyInPin1 = 6;                  //
int KeyInPin2 = 5;                  //
int KeyInPin3 = 8;                  //
int KeyInPin4 = 7;                  //
int KeyInPin5 = 9;
extern uint8_t SmallFontRus[];                         // Подключаем шрифт SmallFontRus.
boolean bf = 0;
boolean b;
boolean l = 0;
boolean g = 0;
boolean f;
boolean h = 0;
boolean flag;
int u = 64;
int r = 15;
int j = -2;
int i = 68;
int k = 0;
int n = 19;
byte d2 = 33;
byte d4 = 33;
byte d6 = 33;
byte d8 = 33;
byte d10 = 33;
byte d12 = 33;
byte d14 = 33;
byte d16 = 33;
byte d18 = 33;
byte d20 = 33;
byte d22 = 33;
byte d24 = 33;
byte d26 = 33;
byte d28 = 33;
byte d30 = 33;
byte d32 = 33;
byte d34 = 33;
byte d36 = 33;
byte d38 = 33;
byte d40 = 33;
byte d42 = 33;
byte d44 = 33;
byte d46 = 33;
byte d48 = 33;
byte d50 = 33;
byte d52 = 33;
byte d54 = 33;
byte d56 = 33;
byte d58 = 33;
byte d60 = 33;
byte d62 = 33;
byte d64 = 31;
byte d66 = 31;
byte d68 = 31;
byte d70 = 31;
byte d72 = 33;
byte d74 = 33;
byte d76 = 33;
byte d78 = 33;
byte d80 = 33;
byte d82 = 33;
byte d84 = 33;
byte d86 = 33;
byte d88 = 33;
byte d90 = 33;
byte d92 = 33;
byte d94 = 33;
byte d96 = 33;
byte d98 = 33;
byte d100 = 33;
byte d102 = 33;
byte d104 = 33;
byte d106 = 33;
byte d108 = 33;
byte d110 = 33;
byte d112 = 33;
byte d114 = 33;
byte d116 = 33;
byte d118 = 33;
byte d120 = 33;
byte you = 0;
iarduino_OLED myOLED1(0x3C);                                // Объявляем объект myOLED, указывая адрес дисплея на шине I2C: 0x3C или 0x3D.
const uint8_t myImageInRAM1[] PROGMEM =                             // Создаём массив myImageInRAM1 содержащий изображение блока. Массив хранится в области ПЗУ (ROM).
{ 30, 2,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
  B11,
};
const uint8_t myImageInRAM2[] PROGMEM =                             // Создаём массив myImageInRAM2 содержащий изображение блока. Массив хранится в области ПЗУ (ROM).
{ 2, 2,
  B01,
  B10,
};
const uint8_t myImageInRAM3[] PROGMEM =                             // Создаём массив myImageInRAM3 содержащий изображение блока. Массив хранится в области ПЗУ (ROM).
{ 2, 2,
  B11,
  B10,
};
const uint8_t myImageInRAM4[] PROGMEM =                             // Создаём массив myImageInRAM4 содержащий изображение блока. Массив хранится в области ПЗУ (ROM).
{ 2, 2,
  B10,
  B11,
};
const uint8_t myImageInRAM[] PROGMEM =                             // Создаём массив myImageInRAM содержащий изображение шахтера. Массив хранится в области ПЗУ (ROM).
{ 8, 16,

  B00001000,
  B01111110,
  B11101111,
  B10111101,
  B10111101,
  B11101111,
  B01111110,
  B00001000,
  //                                 ЛЕВО                 // Первые два числа, это размеры изображения: ширина 8px, высота 16px.(макс.8)
  B00001110,        //               ###     #
  B11111111,        //          ######### ######
  B11111111,        //          ############ ####
  B00011111,        //       НИЗ   ####### #### #ВЕРХ
  B00011111,        //             ####### #### #
  B11111111,        //          ############ ####
  B11111111,        //          ######### ######
  B00001110,        //               ###     #
  //                                 ПРАВО
};
const uint8_t myImageInRAM5[] PROGMEM =
{ 8, 16,

  B00000000,        // Удаляет человечка
  B00000000,        //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  B00000000,        //
  //
};
void setup()
{
  myOLED1.begin();                                    // Инициируем работу с дисплеем.
  myOLED1.setCoding(false);                                           // Отменяем текущую кодировку, так как Русские буквы будем указывать кодом.
  myOLED1.setFont(SmallFontRus);                      // Указываем шрифт который требуется использовать для вывода цифр и текста.
  pinMode(KeyOutPin, OUTPUT);       //4-й пин сконфигурировать как выходной

  pinMode(KeyInPin1, INPUT);        //6-й пин сконфигурировать как входной, кнопка "2"
  digitalWrite(KeyInPin1, HIGH);    //Подтянуть к высокому уровню

  pinMode(KeyInPin2, INPUT);        //5-й пин сконфигурировать как входной, кнопка "1"
  digitalWrite(KeyInPin2, HIGH);    //Подтянуть к высокому уровню

  pinMode(KeyInPin3, INPUT);        //8-й пин сконфигурировать как входной, кнопка "3"
  digitalWrite(KeyInPin3, HIGH);    //Подтянуть к высокому уровню

  pinMode(KeyInPin4, INPUT);        //7-й пин сконфигурировать как входной, кнопка "4"
  digitalWrite(KeyInPin4, HIGH);    //Подтянуть к высокому уровню

  pinMode(KeyInPin5, INPUT);        //9-й пин сконфигурировать как входной, кнопка "5"
  digitalWrite(KeyInPin5, HIGH);    //Подтянуть к высокому уровню

  pinMode(3, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  Serial.begin(9600);               //Открыть последовательный порт для передачи сообщений в монитор порта// Указываем кодировку текста в скетче. Если на дисплее не отображается Русский алфавит, то ...
}
void loop() {
  int del[60] = {d2, d4, d6, d8, d10, d12, d14, d16, d18, d20, d22, d24, d26, d28, d30, d32, d34, d36, d38, d40, d42, d44, d46, d48, d50, d52, d54, d56, d58, d60, d62, d64, d66, d68, d70, d72, d74, d76, d78, d80, d82, d84, d86, d88, d90, d92, d94, d96, d98, d100, d102, d104, d106, d108, d110, d112, d114, d116, d118, d120};
  b = !digitalRead(3);
  f = !digitalRead(10);
  if (b == 1 && bf == 0) {
    delay(1000);
    bf = 1;
    l = !l;
    Serial.print(l);
    Serial.println(" буква l");
  }
  if (b == 0 && bf == 1) {
    bf = 0;
    Serial.print(l);
    Serial.println(" буква l");
  }
  if (l == 0) {
    myOLED1.print("Miner", OLED_C, 39); // Выводим текст "Miner" по центру экрана, координата нижней части текста по оси Y равна 32.
  }
  if (l == 1) {
    if (f == 1 && g == 0) {
      delay(1000);
      g = 1;
      h = !h;
      Serial.print(h);
      Serial.println(" буква h");
    }
    if (f == 0 && g == 1) {
      g = 0;
      Serial.print(h);
      Serial.println(" буква h");
    }
    if (j == -2 || j < 60) {
      j += 2;
      myOLED1.drawImage(myImageInRAM4, j, 17, IMG_ROM);
    }
    if (i == 68 || i < 128) {
      i += 2;
      myOLED1.drawImage(myImageInRAM3, i, 17, IMG_ROM);
    }

    if (k == 0 || k < 120) {
      k += 30;
      myOLED1.drawImage(myImageInRAM1, k, n, IMG_ROM);
      myOLED1.drawImage(myImageInRAM1, 0, 19, IMG_ROM);
      myOLED1.drawImage(myImageInRAM1, 30, 19, IMG_ROM);
      Serial.print(k);
      if (k == 120) {
        n += 2;
        k = -30;
        Serial.println(n);
        if (n == 63) {
          k = 121;
        }
      }
    }

    if (h == 0 && n == 63) {
      myOLED1.drawImage(myImageInRAM, u, r, IMG_ROM);       // Выводим картинку myImageInROM в позицию uxr, указав, что картинка хранится в оперативной памяти (IMG_RAM).
      if (!digitalRead(KeyInPin1))        //Считывание порта - если уровень подтянулся к низкому
      { //значит нажата кнопка, и так со всеми портами
        myOLED1.drawImage(myImageInRAM5, u, r, IMG_ROM);
        if (r == 15) {
          r += 16;
        } else {
          r += 2;
        }
        if (r == del[u / 2]) {
          del[u / 2] += 2;
          del[u / 2 + 1] += 2;
          del[u / 2 + 2] += 2;
          del[u / 2 + 3] += 2;
          you++;
          Serial.print(you);
          Serial.print(del[u]);
        }
        delay(300);
      }
      //if (!digitalRead(KeyInPin2))
      //{
      //}
      if (!digitalRead(KeyInPin3))
      {
        myOLED1.drawImage(myImageInRAM5, u, r, IMG_ROM);
        u -= 2;
        if (u - 3 == j - 1 && r == 31) {
          u += 2;
        }
        delay(300);
      }
      if (!digitalRead(KeyInPin4))
      {
        myOLED1.drawImage(myImageInRAM5, u, r, IMG_ROM);
        if (r == 31) {
          r -= 16;
        } else {
          r -= 2;
          if (r == 31 && u - 3 <= j || r == 31 && u + 3 >= i - 60) {
            r += 2;
          }
        }
        delay(300);
      }
      if (!digitalRead(KeyInPin5))
      {
        myOLED1.drawImage(myImageInRAM5, u, r, IMG_ROM);
        u += 2;
        if (u + 3 == i - 59 && r == 31) {
          u -= 2;
        }
        delay(300);
      }
    }
    if (h == 1) {
    }
  }
  if (l == 0 && flag == 0) {
    myOLED1.clrScr();                                 // Чистим экран.
    flag = 1;
  }
  if (l == 1 && flag == 1) {
    myOLED1.clrScr();                                 // Чистим экран.
    flag = 0;
  }
  if (r == 63) {
    r -= 2;
  }
  if (u == -2) {
    u += 2;
  }
  if (r == 13) {
    r += 2;
  }
  if (u == 120) {
    u -= 2;
  }
  if (u == 66 && r == 15) {
    u -= 2;
  }
  if (u == 62 && r == 15) {
    u += 2;
  }
}
