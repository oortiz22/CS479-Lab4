void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //change when we know which pins data is 
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT); 
  pinMode(13, INPUT); 
  int mm;
  int mf;
  int lf;
  int heel;

  // int sampleMM[] = {0, 0, 0, 0, 20, 23, 25, 50, 100, 100, 112, 122, 90, 70, 60, 50, 40, 20, 0, 0};

}

void loop() {
    int sampleMM[] = {0, 0, 0, 0, 20, 23, 25, 50, 100, 180, 112, 122, 90, 70, 60, 50, 40, 20, 0, 0};
    int sampleMF[] = {0, 0, 0, 0, 20, 23, 25, 50, 40, 100, 0, 122, 90, 70, 60, 50, 40, 20, 0, 0};
    int sampleLF[] = {0, 0, 0, 0, 20, 23, 25, 50, 100, 130, 112, 122, 90, 70, 60, 50, 40, 20, 0, 0};
    int sampleHEEL[] = {0, 0, 0, 0, 20, 23, 25, 50, 23, 100, 112, 122, 90, 70, 60, 50, 40, 20, 0, 0};
  //read data from sensors for each section of the foot
  // mm = analogRead(A1);
  // mf = analogRead(A1);
  // lf = analogRead(A1);
  // heel = analogRead(A1);
  String final;

  for (int i = 0; i < sizeof(sampleMM); i++){
    final = String(i) + "," + String(i) + "," + String(i) + "," + String(i);
    if (isValidFormat(final)){
      Serial.println(final);
    }
    // Serial.println(final);
    delay(300);
  }


  // put your main code here, to run repeatedly:

}

bool isValidFormat(String str) {
  int commaCount = 0;

  for (int i = 0; i < str.length(); i++) {
    char c = str[i];
    
    // Check if each character is a digit or comma
    if (!isDigit(c) && c != ',') {
      return false;
    }

    // Count commas
    if (c == ',') {
      commaCount++;
      // Ensure there is at least one digit before and after each comma
      if (i == 0 || !isDigit(str[i - 1]) || !isDigit(str[i + 1])) {
        return false;
      }
    }
  }
  return (commaCount == 3) && isDigit(str[str.length() - 1]);
}


