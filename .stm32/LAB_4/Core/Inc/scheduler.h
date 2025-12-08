#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#define SCH_MAX_TASK	32
#define NO_TASK_ID 		0
#define TIME_CYCLE 10
#include <stdint.h>
#include "main.h"
#include "scheduler.h"

//typedef struct {
//	void (* pTask)(void);
//	uint32_t Delay;
//	uint32_t Period;
//	uint8_t RunMe;
//	uint32_t TaskID;
//}sTask;

typedef struct {
    void (*pTask)(void);
    uint32_t ExecuteTime;
    uint32_t Period;
    uint8_t Active;
} sTask;


void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY_ms, uint32_t PERIOD_ms);
void SCH_Delete_Task(uint32_t index);


#endif /* INC_SCHEDULER_H_ */
