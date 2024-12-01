#ifndef LIS2DH12_H_
#define LIS2DH12_H_

#define CTRL_REG1 0x20					// lis2dh12 chip registers
#define CTRL_REG4 0x23
#define STATUS_REG 0x27
#define OUT_X_L 0x28
#define OUT_X_H 0x29
#define OUT_Y_L 0x2A
#define OUT_Y_H 0x28
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D
#define FIFO_CTRL_REG 0x2E
#define SAD_W 0x32
#define SAD_R 0x33

void sendOneByteLis2dh(uint8_t sad, uint8_t sub, uint8_t data);
uint8_t getDat(uint8_t regName);
uint16_t accelDatX();
uint16_t accelDatY();
uint16_t accelDatZ();
uint8_t statusLis2dh12();
void initLis2dh12();

#endif
