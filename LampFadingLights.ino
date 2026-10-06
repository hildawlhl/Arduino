const int redPin   = 3;
const int greenPin = 4;
const int bluePin  = 5;

float currentR = 255;
float currentG = 255;
float currentB = 255;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  setColor(255, 255, 255);
}

void loop() {
  fadeToColor(60, 255, 60, 2000);
  delay(2500);

  fadeToColor(0, 180, 255, 1200);
  delay(4000);

  fadeToColor(255, 30, 30, 1800);
  delay(3000);

  fadeToColor(40, 60, 120, 2500);
  delay(2000);
}

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
  currentR = r;
  currentG = g;
  currentB = b;
}

void fadeToColor(int targetR, int targetG, int targetB, int durationMs) {
  int steps = 60;
  float delayPerStep = (float)durationMs / steps;

  float stepR = (targetR - currentR) / steps;
  float stepG = (targetG - currentG) / steps;
  float stepB = (targetB - currentB) / steps;

  for (int i = 0; i < steps; i++) {
    currentR += stepR;
    currentG += stepG;
    currentB += stepB;

    analogWrite(redPin, (int)currentR);
    analogWrite(greenPin, (int)currentG);
    analogWrite(bluePin, (int)currentB);

    delay((int)delayPerStep);
  }

  setColor(targetR, targetG, targetB);
}
