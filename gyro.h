struct msg
{
  //min-s-ms
  unsigned char _ucMinute;//---48->2
  unsigned char _ucSecond;//--50->2
  unsigned short _usMiliSecond;//1000->4  
  
  float _a[3];//acc-加速度-两位小数0.00->4
  float _w[3];//Gyro-角速度-两位小数0.00->4
  float _Angle[3];//Angle-角度-129.18->6
};

msg msgRead();
