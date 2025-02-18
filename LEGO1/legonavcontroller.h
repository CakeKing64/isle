#ifndef LEGONAVCONTROLLER_H
#define LEGONAVCONTROLLER_H

#include "mxcore.h"
#include "mxtimer.h"
#include "mxtypes.h"

// VTABLE 0x100d85b8
// SIZE 0x70
class LegoNavController : public MxCore {
public:
	__declspec(dllexport) static void GetDefaults(
		int* p_mouseDeadzone,
		float* p_movementMaxSpeed,
		float* p_turnMaxSpeed,
		float* p_movementMaxAccel,
		float* p_turnMaxAccel,
		float* p_movementDecel,
		float* p_turnDecel,
		float* p_movementMinAccel,
		float* p_turnMinAccel,
		float* p_rotationSensitivity,
		MxBool* p_turnUseVelocity
	);
	__declspec(dllexport) static void SetDefaults(
		int p_mouseDeadzone,
		float p_movementMaxSpeed,
		float p_turnMaxSpeed,
		float p_movementMaxAccel,
		float p_turnMaxAccel,
		float p_movementDecel,
		float p_turnDecel,
		float p_movementMinAccel,
		float p_turnMinAccel,
		float p_rotationSensitivity,
		MxBool p_turnUseVelocity
	);

	LegoNavController();
	// virtual ~LegoNavController(); // vtable+0x0

	// OFFSET: LEGO1 0x10054b80
	inline const char* ClassName() const override // vtable+0xc
	{
		// 0x100f66d8
		return "LegoNavController";
	}

	// OFFSET: LEGO1 0x10054b90
	inline MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, ClassName()) || MxCore::IsA(name);
	}

	void SetControlMax(int p_hMax, int p_vMax);
	void ResetToDefault();
	void SetTargets(int p_hPos, int p_vPos, MxBool p_accel);
	float CalculateNewTargetSpeed(int p_pos, int p_center, float p_maxSpeed);
	float CalculateNewAccel(int p_pos, int p_center, float p_maxAccel, int p_minAccel);
	float CalculateNewVel(float p_targetVel, float p_currentVel, float p_accel, float p_time);

private:
	int m_hMax;
	int m_vMax;
	int m_mouseDeadzone;
	float m_zeroThreshold;
	float unk_18;
	float unk_1C;
	float m_targetMovementSpeed;
	float m_targetTurnSpeed;
	float m_movementMaxSpeed;
	float m_turnMaxSpeed;
	float m_movementAccel;
	float m_turnAccel;
	float m_movementMaxAccel;
	float m_turnMaxAccel;
	float m_movementMinAccel;
	float m_turnMinAccel;
	float m_movementDecel;
	float m_turnDecel;
	float m_turnSensitivity;
	MxBool m_turnUseVelocity;
	int m_time;
	MxBool m_trackDefault;
	MxBool m_unk5D;
	char m_unk5E[2];
	int m_unk60;
	int m_unk64;
	int m_unk68;
	MxBool m_unk6C;
};

#endif // LEGONAVCONTROLLER_H
