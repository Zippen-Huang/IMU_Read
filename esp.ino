char single[8]; 
char msgBegin[4] = "tim:";
char msgSecond[4] = "acc:";
char msgThird[2] = "w:";
char msgForth[4] = "ang:";
char backSpace[1] = "|";
char Null[2]="\t";
char msgMix1[30];
char msgMix2[30];
char msgMix3[30];
char msgMix4[30];
char msgMix[120];

void ESP_INIT(){
    Serial3.write("AT+CWMODE=1\r\n");
    delay(1000);
    Serial3.write("AT+RST\r\n");
    delay(3000);
    Serial3.write("AT+CWJAP=\"h\",\"hzp123456\"\r\n");
    delay(3000);
    Serial3.write("AT+CIPSTART=\"TCP\",\"192.168.43.174\",8080\r\n");
    delay(4000);
    Serial3.write("AT+CIPMODE=1\r\n");
    delay(2000);
    Serial3.write("AT+CIPSEND\r\n");
    delay(2000);
    //Serial.println(Serial3.readString());
    //delay(1000);
    //String rcvMsg = Serial3.readString();
    //return rcvMsg;
}

void msgSend(){
  strcpy (msgMix1,msgBegin);
  dtostrf(jy901Data->_ucMinute,2,0,single);
  strcat(msgMix1,single);
  strcat (msgMix1,Null);
  dtostrf(jy901Data->_ucSecond,2,0,single);
  strcat(msgMix1,single);
  strcat (msgMix1,Null);
  dtostrf(jy901Data->_usMiliSecond,4,0,single);
  strcat(msgMix1,single);
  strcat (msgMix1,Null);
  
  strcat (msgMix1,backSpace);
  Serial3.write(msgMix1);

  strcpy (msgMix2,msgSecond);
  for(char i=0;i<3;i++){
    dtostrf(jy901Data->_a[i],3,2,single);
    strcat (msgMix2,single);
    strcat (msgMix2,Null);
  }
  strcat (msgMix2,backSpace);
  Serial3.write(msgMix2);

  strcpy(msgMix3,msgThird);
  for(char i=0;i<3;i++){
    dtostrf(jy901Data->_w[i],3,2,single);
    strcat (msgMix3,single);
    strcat (msgMix3,Null);
  }
  strcat (msgMix3,backSpace);
  Serial3.write(msgMix3);

  strcpy(msgMix4,msgForth);
  for(char i=0;i<3;i++){
    dtostrf(jy901Data->_Angle[i],4,2,single);
    strcat (msgMix4,single);
    strcat (msgMix4,Null);
  }
  strcat(msgMix4,"\r\n");
  Serial3.write(msgMix4);
}

void mixMsgSend(){
  strcpy (msgMix,msgBegin);
  dtostrf(jy901Data->_ucMinute,2,0,single);
  strcat(msgMix,single);
  strcat (msgMix,Null);
  dtostrf(jy901Data->_ucSecond,2,0,single);
  strcat(msgMix,single);
  strcat (msgMix,Null);
  dtostrf(jy901Data->_usMiliSecond,4,0,single);
  strcat(msgMix,single);
  strcat (msgMix,Null);
  
  strcat (msgMix,backSpace);

  strcat (msgMix,msgSecond);
  for(char i=0;i<3;i++){
    dtostrf(jy901Data->_a[i],3,2,single);
    strcat (msgMix,single);
    strcat (msgMix,Null);
  }
  strcat (msgMix,backSpace);

  strcat(msgMix,msgThird);
  for(char i=0;i<3;i++){
    dtostrf(jy901Data->_w[i],3,2,single);
    strcat (msgMix,single);
    strcat (msgMix,Null);
  }
  strcat (msgMix,backSpace);

  strcat(msgMix,msgForth);
  for(char i=0;i<3;i++){
    dtostrf(jy901Data->_Angle[i],4,2,single);
    strcat (msgMix,single);
    strcat (msgMix,Null);
  }
  strcat(msgMix,"\r\n");
  Serial3.write(msgMix);
}
