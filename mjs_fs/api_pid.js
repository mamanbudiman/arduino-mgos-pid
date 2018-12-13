// Arduino PID library API. Source C API is defined at:
// [mgos_arduino_PWMServoDriver.h]


let PID = {
  _create: ffi('void *mgos_PID_create(double*, double*, double*, double, double, double, int, int)'),
  _close: ffi('void mgos_PID_close(void *)'),	
  _compute: ffi('bool mgos_PID_Compute(void *)'),	
  _stn: ffi('void mgos_PID_setTunings(void *, double, double, double, int)'),	
  _sst: ffi('void mgos_PID_SetSampleTime(void *, int)'),	
  _sol: ffi('void mgos_PID_SetOutputLimits(void *, double, double)'),	
  _mode: ffi('void mgos_PID_SetMode(void *, int)'),	
  _init: ffi('void mgos_PID_Initialize(void *)'),	
  _scd: ffi('void mgos_PID_SetControllerDirection(void *, int)'),	
  _kp: ffi('double mgos_PID_GetKp(void *)'),	
  _ki: ffi('double mgos_PID_GetKi(void *)'),	
  _kd: ffi('double mgos_PID_GetKd(void *)'),	
  _gmode: ffi('int mgos_PID_GetMode(void *)'),	
  _gdir: ffi('int mgos_PID_GetDirection(void *)'),
  
  // ## **`PID.create()`**
  // Create an instance of PID with the methods described below.
  create: function(Input, Output, Setpoint, Kp, Ki, Kd, POn, ControllerDirection) {
    let obj = Object.create(PID._proto);
    obj.pid = PID._create(Input, Output, Setpoint, Kp, Ki, Kd, POn, ControllerDirection);
    return obj;
  },

  _proto: {
    
    close: function() {
      return PID._close(this.pid);
    },

    compute: function() {
      return PID._compute(this.pid);
    },

    setTunings: function(Kp, Ki, Kd, POn) {
      return PID._stn(this.pid, Kp, Ki, Kd, POn);
    },

    setSampleTime: function(NewSampleTime) { 
      return PID._sst(this.pid, NewSampleTime);
    },

    setOutputLimits: function(Min, Max) {
      return PID._sol(this.pid, Min, Max);
    },

    setMode: function(Mode) {
      return PID._mode(this.pid, Mode);
    },

    initialize: function() {
      return PID._init(this.pid);
    },

    setControllerDirection: function(ControllerDirection) {
      return PID._scd(this.pid, ControllerDirection);
    },

    getKp: function() {
      return PID._kp(this.pid);
    },

    getKi: function() {
      return PID._ki(this.pid);
    },

    getKd: function() {
      return PID._kd(this.pid);
    },

    getMode: function() {
      return PID._gmode(this.pid);
    },

    getDirection: function() {
      return PID._gdir(this.pid);
    },
  },
}
