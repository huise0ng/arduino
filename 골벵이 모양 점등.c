#include <LedControl.h>

LedControl lc = LedControl(12, 10, 11, 1); // DIN, CLK, CS, 갯수

void setup() {
  lc.shutdown(0, false); // 라이브러리 초기화
  lc.setIntensity(0, 8); // 밝기 설정 (0 ~ 15)
  lc.clearDisplay(0); // 디스플레이 지우기
}

void loop() {
  rotateAndFadeEffect();
  delay(100); // 효과 간 딜레이
}

void rotateAndFadeEffect() {
  for (int i = 0; i < 4; i++) {
    // 왼쪽 변
    for (int row = i; row <= 7 - i; row++) {
      lc.setLed(0, i, row, HIGH);
      delay(50); // 효과 속도 조절을 위한 딜레이
    }

    // 아래쪽 변
    for (int col = i + 1; col <= 6 - i; col++) {
      lc.setLed(0, col, 7 - i, HIGH);
      delay(50); // 효과 속도 조절을 위한 딜레이
    }

    // 오른쪽 변
    for (int row = 7 - i; row >= i; row--) {
      lc.setLed(0, 7 - i, row, HIGH);
      delay(50); // 효과 속도 조절을 위한 딜레이
    }

    // 위쪽 변
    for (int col = 6 - i; col >= i + 1; col--) {
      lc.setLed(0, col, i, HIGH);
      delay(50); // 효과 속도 조절을 위한 딜레이
    }
  }

  delay(500); // 전체 점등 상태 유지를 위한 딜레이
  lc.clearDisplay(0); // 디스플레이 지우기
}