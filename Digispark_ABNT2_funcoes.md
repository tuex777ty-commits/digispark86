# Digispark – Funções para teclado ABNT2

## Objetivo

Este documento guarda funções descobertas durante os testes com o Digispark ATtiny85 usando a biblioteca `DigiKeyboard`.

A biblioteca padrão usa códigos de teclado que podem ser interpretados de forma diferente quando o Windows está usando o layout brasileiro ABNT2. As funções abaixo servem para produzir alguns caracteres especiais corretamente.

> **Importante:** estes mapeamentos foram testados em um ambiente específico com Windows/ABNT2. Podem variar conforme o layout/configuração do computador.

---

## Biblioteca

```cpp
#include "DigiKeyboard.h"
```

---

## `:` dois-pontos

O teste mostrou que o código HID `56` com `Shift` produz `:` no ambiente testado.

```cpp
void doisPontos() {
  DigiKeyboard.sendKeyStroke(56, MOD_SHIFT_LEFT);
}
```

Uso:

```cpp
DigiKeyboard.print("https");
doisPontos();
```

Resultado:

```text
https:
```

---

## `/` barra

No ambiente testado, `Ctrl + Alt + Q` produz `/`.

```cpp
void barra() {
  DigiKeyboard.sendKeyStroke(
    KEY_Q,
    MOD_CONTROL_LEFT | MOD_ALT_LEFT
  );
}
```

Uso:

```cpp
barra();
barra();
```

Resultado:

```text
//
```

---

## Exemplo: digitar uma URL

```cpp
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

  DigiKeyboard.print("https");

  doisPontos();

  barra();
  barra();

  DigiKeyboard.print("exemplo.com");

  barra();

  while (true) {
    DigiKeyboard.delay(1000);
  }
}
```

Produz:

```text
https://exemplo.com/
```

---

## Teclas úteis

### Abrir Executar (Win + R)

```cpp
DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
```

### Ctrl + A

```cpp
DigiKeyboard.sendKeyStroke(KEY_A, MOD_CONTROL_LEFT);
```

### Ctrl + C

```cpp
DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
```

### Ctrl + V

```cpp
DigiKeyboard.sendKeyStroke(KEY_V, MOD_CONTROL_LEFT);
```

### Ctrl + W

```cpp
DigiKeyboard.sendKeyStroke(KEY_W, MOD_CONTROL_LEFT);
```

### Enter

```cpp
DigiKeyboard.sendKeyStroke(KEY_ENTER);
```

---

## Exemplo de sequência HID

```cpp
// Win + R
DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
DigiKeyboard.delay(500);

// Digita texto
DigiKeyboard.print("ola mundo");

// Copia
DigiKeyboard.sendKeyStroke(KEY_A, MOD_CONTROL_LEFT);
DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);

// Fecha a janela/aba quando aplicável
DigiKeyboard.sendKeyStroke(KEY_W, MOD_CONTROL_LEFT);

// Cola
DigiKeyboard.sendKeyStroke(KEY_V, MOD_CONTROL_LEFT);
```

---

## Tabela de caracteres já testados

| Caractere desejado | Método |
|---|---|
| `:` | `sendKeyStroke(56, MOD_SHIFT_LEFT)` |
| `/` | `Ctrl + Alt + Q` |

### Caracteres ainda não mapeados

- `@`
- `*`
- `_`
- `;`
- `?`
- `\`
- `{`
- `}`
- `|`
- `[`
- `]`

Para descobrir outros caracteres, faça testes com `sendKeyStroke()` e anote:

```text
código HID + modificador → caractere produzido
```

---

## Boas práticas

1. Teste cada caractere individualmente antes de colocá-lo em uma URL.
2. Não altere `scancode-ascii-table.h` sem fazer backup.
3. Lembre que o resultado depende do layout do teclado do computador.
4. Use `delay()` entre ações HID para dar tempo ao Windows de processar as teclas.
5. Para testes de automação, prefira conteúdos inofensivos, como `Ola mundo`.
6. Evite executar automaticamente conteúdo copiado de páginas da internet.

---

## Exemplo de projeto mínimo

```cpp
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

  DigiKeyboard.print("https");

  doisPontos();

  barra();
  barra();

  DigiKeyboard.print("exemplo.com");

  barra();

  while (true) {
    DigiKeyboard.delay(1000);
  }
}
```

---

## Registro

Ambiente em que os testes foram realizados:

- Digispark ATtiny85
- Biblioteca `DigiKeyboard`
- Windows
- Layout de teclado ABNT2
- Arduino/Digispark AVR 1.6.7

Este arquivo deve ser atualizado conforme novos caracteres forem testados.
