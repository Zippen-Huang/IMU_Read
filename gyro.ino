msg msgRead(){
   msg tempMsg;
  JY901.GetTime();
  tempMsg._ucMinute = JY901.stcTime.ucMinute;
  tempMsg._ucSecond = JY901.stcTime.ucSecond;
  tempMsg._usMiliSecond = JY901.stcTime.usMiliSecond;
  
  JY901.GetAcc();
  tempMsg._a[0] = (float)JY901.stcAcc.a[0]/32768*16;
  tempMsg._a[1] = (float)JY901.stcAcc.a[1]/32768*16;
  tempMsg._a[2] = (float)JY901.stcAcc.a[2]/32768*16;
  
  JY901.GetGyro();
  tempMsg._w[0] = (float)JY901.stcGyro.w[0]/32768*2000;
  tempMsg._w[1] = (float)JY901.stcGyro.w[1]/32768*2000;
  tempMsg._w[2] = (float)JY901.stcGyro.w[2]/32768*2000;
  
  JY901.GetAngle();
  tempMsg._Angle[0] = (float)JY901.stcAngle.Angle[0]/32768*180;
  tempMsg._Angle[1] = (float)JY901.stcAngle.Angle[1]/32768*180;
  tempMsg._Angle[2] = (float)JY901.stcAngle.Angle[2]/32768*180;

  return tempMsg;
}

