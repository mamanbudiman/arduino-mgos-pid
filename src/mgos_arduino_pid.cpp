
#include "mgos_arduino_pid.h"

PID *mgos_PID_create(double* Input, double* Output, double* Setpoint,
        double Kp, double Ki, double Kd, int POn, int ControllerDirection) {
   return new PID(Input, Output, Setpoint, Kp, Ki, Kd, POn, ControllerDirection);                        
}

void mgos_PID_close(PID *pid) {
  if (pid != nullptr) {
    delete pid;
    pid = nullptr;
  }
}

bool mgos_PID_Compute(PID *pid) {
  if (pid == nullptr) return false;
  return pid->Compute();
}
  
void mgos_PID_setTunings(PID *pid, double Kp, double Ki, double Kd, int POn) {
  if (pid == nullptr) return;
  pid->SetTunings(Kp, Ki, Kd, POn);
}
  
void mgos_PID_SetSampleTime(PID *pid, int NewSampleTime) {
  if (pid == nullptr) return;
  pid->SetSampleTime(NewSampleTime);
}

void mgos_PID_SetOutputLimits(PID *pid, double Min, double Max) {
  if (pid == nullptr) return;
  pid->SetOutputLimits(Min, Max);
}
  
void mgos_PID_SetMode(PID *pid, int Mode) {
  if (pid == nullptr) return;
  pid->SetMode(Mode);
}
  
void mgos_PID_Initialize(PID *pid) {
  if (pid == nullptr) return;
  pid->Initialize();
}   
  
void mgos_PID_SetControllerDirection(PID *pid, int Direction) {
  if (pid == nullptr) return;
  pid->SetControllerDirection(Direction);
}

double mgos_PID_GetKp(PID *pid) {
  if (pid == nullptr) return 0;
  return pid->GetKp();
}

double mgos_PID_GetKi(PID *pid) {
  if (pid == nullptr) return 0;
  return pid->GetKi();
}

double mgos_PID_GetKd(PID *pid) {
  if (pid == nullptr) return 0;
  return pid->GetKd();
}
    
int mgos_PID_GetMode(PID *pid) {
  if (pid == nullptr) return 0;
  return pid->GetMode();
}

int mgos_PID_GetDirection(PID *pid) {
  if (pid == nullptr) return 0;
  return pid->GetDirection();
}
