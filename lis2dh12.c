#include "twi.h"
#include "lis2dh12.h"

void sendOneByteLis2dh(uint8_t sad, uint8_t sub, uint8_t data) {
   startConditionTWI();						// start
   sendTWI(sad);							// sad + w
   sendTWI(sub);							// sub (addr reg lis2dh12)
   sendTWI(data);							// data
   stopConditionTWI();						// stop
}

uint8_t getDat(uint8_t regName) {					// receiving data
   startConditionTWI();
   sendTWI(SAD_W);
   sendTWI(regName);
   startConditionTWI();
   sendTWI(SAD_R);
   uint8_t data = lastReadTWI();
   stopConditionTWI();
   return data;
}

uint16_t accelDatX() {						// getting X axis data
   uint8_t var = 0;
   var = getDat(OUT_X_L);
   var |= getDat(OUT_X_H) << 8;
   return var;
}

uint16_t accelDatY() {						// getting Y axis data
   uint8_t var = 0;
   var = getDat(OUT_Y_L);
   var |= getDat(OUT_Y_H) << 8;
   return var;
}

uint16_t accelDatZ() {						// getting Z axis data
   uint8_t var = 0;
   var = getDat(OUT_Z_L);
   var |= getDat(OUT_Z_H) << 8;
   return var;
}

uint8_t statusLis2dh12() {						// getting status lis2dh12
   startConditionTWI();
   sendTWI(SAD_W);
   sendTWI(STATUS_REG);
   startConditionTWI();
   sendTWI(SAD_R);
   uint8_t stat = lastReadTWI();
   stopConditionTWI();
   return stat;
}

void initLis2dh12() {
   sendOneByteLis2dh(SAD_W, FIFO_CTRL_REG, 0x00);				// bypass mode
   sendOneByteLis2dh(SAD_W, CTRL_REG4, 0x38);				// data 8bit, overload 16g
   sendOneByteLis2dh(SAD_W, CTRL_REG1, 0x9F);				// speed 50Hz, axes selection XYZ
}
