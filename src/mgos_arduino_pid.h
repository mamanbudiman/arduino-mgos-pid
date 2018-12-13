/*
 * Arduino PID library API wrapper
 */

#include "PID.h"

#ifdef __cplusplus
extern "C"
{
#endif

PID *mgos_PID_create(double* Input, double* Output, double* Setpoint,
        double Kp, double Ki, double Kd, int POn, int ControllerDirection);

void mgos_PID_close(PID *pid);
	
bool mgos_PID_Compute(PID *pid);
	
void mgos_PID_setTunings(PID *pid, double Kp, double Ki, double Kd, int POn);
	
void mgos_PID_SetSampleTime(PID *pid, int NewSampleTime);
	
void mgos_PID_SetOutputLimits(PID *pid, double Min, double Max);
	
void mgos_PID_SetMode(PID *pid, int Mode);
	
void mgos_PID_Initialize(PID *pid);
	
void mgos_PID_SetControllerDirection(PID *pid, int Direction);
	
double mgos_PID_GetKp(PID *pid);
	
double mgos_PID_GetKi(PID *pid);
	
double mgos_PID_GetKd(PID *pid);
	
int mgos_PID_GetMode(PID *pid);
	
int mgos_PID_GetDirection(PID *pid);	   

#ifdef __cplusplus
}
#endif  /* __cplusplus */
