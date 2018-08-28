# IMU_Read
function:read gyro data through uart and send them to pc by wifi

the main ideal of code is that improve sending AT commamd lines  by uart assistant manually to sending AT commamd lines  by arduino code automatically.
and then, read gyro data by IIC communication protacol
electronic component table:
1 arduino mega2560
2 wifi:esp0826  use AT command

wifi mode:AP
wifiname:h
wifipassword:hzp123456

please test wifi by uart assistant, send AT command line to wifi to ensure wifi can work fine.

